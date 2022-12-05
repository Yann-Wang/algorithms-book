var nLine = 0;
    var n,nn=1,i;
    var str,len,count=0;

    n=500;
    
    for(i=1;i<=n;++i){
        nn = nn*i;
    }
    console.log(nn);
    
    str = nn.toString();
    console.log(str);
    len = str.length;
    console.log(len);
    for(i=len-1;i>=0;--i){
        if(str[i] === '0'){
            count++;
            
        }else{
            break;
        }
        
        
    }
    
    console.log(count);