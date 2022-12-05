var minimumTotal = function(triangle) {
    var createTwoDemensionArray = function (i,j) {
        var arr = new Array(i);
        for (var i=0;i<arr.length;i++) {
            arr[i] = new Array(j);
        }
        return arr;
    }
    var m = triangle.length;
    var n = triangle[m-1].length;
    var i,j;
    var d = createTwoDemensionArray(m, n);
    console.log(d);
    d[m-1] = triangle[m-1];
    for (i= m-2;i>=0;i--) {
        for(j=0;j<triangle[i].length;j++) {
            d[i][j] = triangle[i][j] + Math.min(d[i+1][j], d[i+1][j+1]);
        }
    }
    return d[0][0];
};

var result = minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]);
console.log(result)
