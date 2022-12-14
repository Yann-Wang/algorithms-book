
const PENDING = 'pending';
const FULFILLED = 'fulfilled';
const REJECTED = 'rejected';

function MyPromise(executor) {
    this.value = null;
    this.error = null;
    this.status = PENDING;
    this.onFulfilledCallbacks = [];
    this.onRejectedCallbacks = [];

    const resolve = (value) => {
        if (this.status !== PENDING) {
            return;
        }

        queueMicrotask(() => {
            this.status = FULFILLED;
            this.value = value;
            this.onFulfilledCallbacks.forEach(callback => callback(this.value)); 
        })
    };

    const reject = (error) => {
        if (this.status !== PENDING) {
            return;
        }

        queueMicrotask(() => {
            this.status = REJECTED;
            this.error = error;
            this.onRejectedCallbacks.forEach(callback => callback(this.error));
        });
    };

    try {
        executor(resolve, reject);
    } catch (e) {
        reject(e);
    }

};

MyPromise.prototype.then = function(onFulfilled, onRejected) {

    onFulfilled = typeof onFulfilled === 'function' ? onFulfilled : value => value;
    onRejected = typeof onRejected === 'function' ? onRejected : error => {throw error};

    let bridgePromise;
    if (this.status === PENDING) {

        return bridgePromise = new MyPromise((resolve, reject) => {
            this.onFulfilledCallbacks.push(value => {
                try {
                    let x= onFulfilled(value);
                    resolvePromise(bridgePromise, x, resolve, reject);
                } catch(e){
                    reject(e);
                }
            });

            this.onRejectedCallbacks.push(error => {
                try {
                    let x = onRejected(error);
                    resolvePromise(bridgePromise, x, resolve, reject);
                } catch(e) {
                    reject(e);
                }
            });
        })
    } else if (this.status === FULFILLED) {
        return bridgePromise = new MyPromise((resolve, reject) => {
            queueMicrotask(() => {
                try {
                    let x= onFulfilled(this.value);
                    resolvePromise(bridgePromise, x, resolve, reject);
                } catch (e) {
                    reject(e);
                }
            })
            
        })
    } else {
        return bridgePromise = new MyPromise((resolve, reject) => {
            queueMicrotask(() => {
                try {
                    let x= onRejected(this.error);
                    resolvePromise(bridgePromise, x, resolve, reject);
                } catch(e) {
                    reject(e);
                }
            })
            
        })
    }

};

function resolvePromise(bridgePromise, x, resolve, reject) {
    if (bridgePromise === x) {
        throw new TypeError('bridgePromsie must not equal to x');
    }
    if (x instanceof MyPromise) {
        if (x.status === PENDING) {
            x.then(y => {
                resolvePromise(bridgePromise, y, resolve, reject);
            }, error => {
                reject(error);
            });
        } else {
            x.then(resolve, reject);
        }
    } else if (typeof x === 'object' || typeof x === 'function') {
        if (x === null) {
            return resolve(x);
        }
    
        try {
            var then = x.then;
        } catch (error) {
            return reject(error); 
        }
    
        // ?????? then ?????????
        if (typeof then === 'function') {
            var called = false;
            // ??? x ???????????????????????? this ?????????
            // ???????????????????????????????????????????????????????????? resolvePromise ???????????????????????? rejectPromise
            // ?????????????????????????????????????????????
            try {
                then.call(
                x,
                // ?????? resolvePromise ?????? y ?????????????????????????????? [[Resolve]](promise, y)
                function (y) {
                    // ?????? resolvePromise ??? rejectPromise ???????????????
                    // ??????????????????????????????????????????????????????????????????????????????????????????
                    // ???????????????????????????????????????called
                    if (called) return;
                    called = true;
                    resolvePromise(bridgePromise, y, resolve, reject);
                },
                function (r) {
                    if (called) return;
                    called = true;
                    reject(r);
                });
            } catch (error) {
                if (called) return;
        
                reject(error);
            }
        } else {
            resolve(x);
        }
    } else {
        resolve(x);
    }
}

MyPromise.prototype.catch = function(onRejected) {
    return this.then(null, onRejected);
};


MyPromise.deferred = function() {
    var result = {};
    result.promise = new MyPromise(function(resolve, reject){
      result.resolve = resolve;
      result.reject = reject;
    });
  
    return result;
}

MyPromise.resolve = param => {
    if (param instanceof MyPromise) {
        return param;
    }

    return new MyPromise((resolve, reject) => {
        if (param && param.then && typeof param.then === 'function') {
            param.then(resolve, reject);
        } else {
            resolve(param);
        }
    });
};

MyPromise.reject = function(reason) {
    return new MyPromise((resolve, reject) => {
        reject(reason);
    });
};

MyPromise.prototype.finally = function(callback) {
    this.then(value => {
        return Promise.resolve(callback()).then(() => {
            return value;
        })
    }, error => {
        return Promise.resolve(callback()).then(() => {
            throw error;
        });
    })
};

MyPromise.all = function(promises) {
    return new MyPromise((resolve, reject) => {
        let result = [];
        let index = 0;
        let len = promises.length;
        if (len === 0) {
            resolve(result);
            return;
        }

        for (let i=0;i<len;i++) {
            MyPromise.resolve(promises[i]).then(data => {
                result[i] = data;
                index++;
                if (index === len) {
                    resolve(result);
                }
            }).catch(err => {
                reject(err);
            });
        }
    });
};

MyPromise.race = function(promises) {
    return new MyPromise((resolve, reject) => {
        let len = promises.length;
        if (len === 0) {
            resolve();
            return;
        }

        for (let i=0; i<len;i++) {
            MyPromise.resolve(promises[i]).then(data => {
                resolve(data); // ????????????????????????????????????MyPromise?????????resolve??????????????????
                return;
            }).catch(err => {
                reject(err);
                return;
            })
        }
    })
}

module.exports = MyPromise;
