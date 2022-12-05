
function Floyd(g, A, Path){
	var i,j,k;

	for(i=0;i<g.n;++i)
		for(j=0;j<g.n;++j){
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}

	for(k=0;k<g.n;++k)
		for(i=0;i<g.n;++i)
			for(j=0;j<g.n;++j)
				if(A[i][j]> A[i][k]+A[k][j]){
					A[i][j] = A[i][k]+A[k][j];
					Path[i][j] = k;
				}
}



function shortestPath(u,v,path){
	var shortestPathFromUtoV = [];

	function printPath(u,v,path){
		shortestPathFromUtoV.push(u);
		if(path[u][v] === -1){
			shortestPathFromUtoV.push(v);
		}			
		else{
			var mid=path[u][v];
			printPath(mid,v,path);
		}

	}

	printPath(u,v,path);
	console.log(shortestPathFromUtoV);
}

var edges =[[0,5,Infinity,7],[Infinity,0,4,2],[3,3,0,2],[Infinity,Infinity,1,0]];

var AdjacencyMatrix = {
	edges: edges,
	n: 4,
	e: 8,
	vex: [{no:1,info:"1"},{no:2,info:"2"},{no:3,info:"3"},{no:4,info:"4"}]
};

var shortestPathLength = [[,,,],[,,,],[,,,],[,,,]];
var middleVextex = [[,,,],[,,,],[,,,],[,,,]];



Floyd(AdjacencyMatrix,shortestPathLength,middleVextex);

shortestPath(1,0,middleVextex);