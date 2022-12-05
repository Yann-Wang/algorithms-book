function mapLimit(list, limit) {
	function recursion(arr) {

        let item = arr.shift();

        console.log('start', item);
		return fetch2(item)
			.then(() => {
                console.log('end', item);
				if(arr.length !== 0) return recursion(arr) // 数组还未迭代完，递归继续进行迭代 
				else return 'finish';
			})
	};

	let listCopy = [].concat(list);
	let asyncList = []; // 正在进行的所有并发异步操作 
	
	while(limit--) {
		asyncList.push(recursion(listCopy));
	}
	return Promise.all(asyncList); // 所有并发异步操作都完成后，本次并发控制迭代完成 // 对于每一个item, 只要其后then的回调函数返回的是promise， 就不算结束
}

function fetch2(url) {
    return new Promise((resolve, reject) => {
        const time = parseInt(4000 * Math.random());  
    
        setTimeout(() => {
            resolve(url);
        }, time)
    })

}

const urls = ['u1', 'u2', 'u3', 'u4', 'u5', 'u6'];
const cb = (value) => {console.log('cb: ', value);}

mapLimit(urls, 3).then(cb);