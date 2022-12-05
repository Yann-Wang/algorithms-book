
function multiway_tree_traversal(){
	var stack = [],top = -1,oNode;
	var oNodeStyle,oNodeWidth,oNodeHeight;
	var targetNode = [],k=0;
	var oChildNodesList,i;

	stack[++top] = document.body;

	while(top !== -1){
		oNode = stack[top--];
		oNodeStyle = getComputedStyle(oNode,null);
		oNodeWidth = +oNodeStyle.width.slice(0,-2);
		oNodeHeight = +oNodeStyle.height.slice(0,-2);
		if(oNodeWidth>50 && oNodeHeight>50){
			targetNode[k++] = oNode;
		}

		oChildNodesList = oNode.children;
		for(i=0,len=oChildNodesList.length;i<len;++i){
			stack[++top] = oChildNodesList[i];
		}
	}

	console.log(targetNode);
}

multiway_tree_traversal();