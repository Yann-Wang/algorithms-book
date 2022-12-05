const isObject = target => (typeof target === 'object' || typeof target === 'function') && target !== null;

const getType = obj => Object.prototype.toString.call(obj);

const canTraverse = {
    '[object Map]': true,
    '[object Set]': true,
    '[object Array]': true,
    '[object Object]': true,
    '[object Arguments]': true
};

const boolTag = '[object Boolean]';
const numberTag = '[object Number]';
const stringTag = '[object String]';
const symbolTag = '[object Symbol]';

const dateTag = '[object Date]';
const errorTag = '[object Error]';
const regexpTag = '[object RegExp]';
const funcTag = '[object Function]';
const mapTag = '[object Map]';
const setTag = '[object Set]';

const handleRegExp = target => {
    const { source, flags } = target;
    return new target.constructor(source, flags);
};

const handleFunc = target => {
    // 箭头函数的prototype === null
    if (!target.prototype) {
        return target;
    }
    const bodyReg = /(?<={)(.|\n)*(?=})/m;
    const paramsReg = /(?<=\().*(?=\)\s+{)/;
    const funcString = target.toString();

    const params = paramsReg.exec(funcString);
    const body = bodyReg.exec(funcString);

    if (!body) {
        return null;
    }
    if (params) {
        const paramsArr = params[0].split(',');
        return new Function(...paramsArr, body[0]);
    }
    return new Function(body[0]);
}

const handleNotTraverse = (target, tag) => {
    const Ctor = target.constructor;

    switch(tag) {
        case boolTag: 
            return new Object(Boolean.prototype.valueOf.call(target));
        case numberTag: 
            return new Object(Number.prototype.valueOf.call(target));
        case stringTag:
            return new Object(String.prototype.valueOf.call(target));
        case symbolTag:
            return new Object(Symbol.prototype.valueOf.call(target));
        case errorTag:
        case dateTag:
            return new Ctor(target);
        case regexpTag:
            return handleRegExp(target);
        case funcTag:
            return handleFunc(target);
        default:
            return new Ctor(target);
    }
}

const deepClone = (target, map = new WeakMap()) => {
    if (!isObject(target)) {
        return target;
    }
    let type = getType(target);
    let cloneTarget;
    if (!canTraverse[type]) {
        // 处理不能遍历的对象
        return handleNotTraverse(target, type);
    }

    let ctor = target.constructor;
    cloneTarget = new ctor();

    if (map.get(target)) {
        return target;
    }

    map.set(target, true);

    if (type === mapTag) {
        //处理Map
        target.forEach((item, key) => {
            cloneTarget.set(deepClone(key, map), deepClone(item, map));
        });
    }

    if (type === setTag) {
        //处理Set
        target.forEach(item => {
            cloneTarget.add(deepClone(item, map));
        });
    }

    // 处理数组和对象
    for(let prop in target) {
        if (target.hasOwnProperty(prop)) {
            cloneTarget[prop] = deepClone(target[prop], map);
        }
    }

    return cloneTarget;
};