
/*
* n {Number} 物品数量
* c {Array} 物品体积
* w {Array} 物品价值
* arr {Array} 不同容量的背包所能装入的最大价值
*/
function zeroOnePack(n,c,w,arr){
	var i=0,cost,v;
	for(i=0;i<n;i++){
		cost = c[i];
		for(v=V;v>=cost;v--){
			arr[v] = arr[v]>arr[v-c[i]]+w[i]?arr[v]:arr[v-c[i]]+w[i];
		}
	}
}



var volumn = [10,20,30,10,20];
var n = volumn.length;
var worth = [60,100,120,30,40];
var V = 50;

var arr = new Array(V+1);

for(var i=0;i<arr.length;i++)
	arr[i] = i===0 ? 0 : -Infinity;

zeroOnePack(n, volumn, worth, arr);
console.log(arr[V]);

