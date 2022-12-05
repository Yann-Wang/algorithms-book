function fetch(url) {
    return new Promise((resolve, reject) => {
        const time = parseInt(4000 * Math.random());  
    
        setTimeout(() => {
            if (time > 3500) {
                reject(url);
                return;
            }
            resolve(url);
        }, time)
    })

}

function sendRequest(urls, max, callback) {
    // urls: string[], max: 0, callback: void => {}
    // 通过max控制并发度
    // 请求完成后调用callback
    // 请求可以直接用fetch

    return new Promise((resolve, reject) => {
        let count = 0;
        let urlsCopy = [].concat(urls);
        let len = urls.length;
        let result = new Array(len).fill(false);
        let k = 0;

        function request () {
            let i = k;
            k++;
            count++;
            console.log('start', i)
            fetch(urlsCopy.shift()).then(res => {
                console.log('end', i);
                result[i] = res;

                if (result.every(it => it)) {
                    resolve(result)
                }
                count--;
            }).then(diaodu).catch(err => {
                console.log('end err', i);
                result[i] = err;
                if (result.every(it => it)) {
                    resolve(result)
                }
                count--;
            })
        }

        function diaodu() {
            if (urlsCopy.length > 0 && count <= max) {
                request();
            }
        }

        for (let j=0;j<max && j<len;j++) {
            request();
        }
    }).then(callback);
    
}

const urls = ['u1', 'u2', 'u3', 'u4', 'u5', 'u6'];
const cb = (value) => {console.log('cb: ', value);}

sendRequest(urls, 3, cb);