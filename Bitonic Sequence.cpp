
lld ceilIndex(lld arr[],lld l,lld r,lld key){
        while (r - l > 1) { 
		lld m = l + (r - l) / 2; 
		if (arr[m] >= key) 
			r = m; 
		else
			l = m; 
	} 

	return r;
    }
lld longestincsubseq(lld arr[],lld n,lld metr[]){
      lld tail[n];
      lld length=1;
      tail[0]=arr[0],metr[0]=1;
      itr(i,1,n-1){
           if(arr[i]<tail[0]){
                   tail[0]=arr[i]; 
                   metr[i]=1;
            }
           else if(arr[i]>tail[length-1]){
                  tail[length++]=arr[i];
                  metr[i]=length;
            }
           else{
                   tail[ceilIndex(tail,-1,length-1,arr[i])]=arr[i];
                   metr[i]=ceilIndex(tail,-1,length-1,arr[i])+1;
            }
    }
  return length;
}

void reverseArray(lld arr[],lld low,lld high){
    if(low>=high)  return;
    else{
        lld temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        return reverseArray(arr,low+1,high-1);
    }
}       
       
lld bitonic(lld arr[],lld n){
    lld tail1[n],tail2[n];
    longestincsubseq(arr,n,tail1);
    reverseArray(arr,0,n-1);
    longestincsubseq(arr,n,tail2);
    reverseArray(tail2,0,n-1);
    lld ans=0;
    itr(i,0,n-1){
        if(ans<=(tail1[i]+tail2[i]-1))
           ans=tail1[i]+tail2[i]-1;
    }
    return ans;
}
