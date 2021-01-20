int findPlatform(int arr[], int dep[], int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);

	int start = 0;
	int maxocc = 0,currentocc = 0;
	int currentarr = 0,currentdep = 0,depp = 0;
	while(start<n){
	    if(start==0){
	        currentarr = arr[start];
	        currentdep = dep[start];
	        maxocc = 1;
	        currentocc = 1;
	        depp = 0;
	        start++;
	    }
	    else{
	        currentarr = arr[start];
	        if(currentarr<=currentdep){
	            currentocc++;
	            maxocc = max(maxocc,currentocc);
	            start++;
	        }
	        else{
	            while(depp<n and dep[depp]<currentarr){
	                currentocc--;
	                depp++;
	            }

	            currentdep = dep[depp];
	            currentocc++;
	            start++;
	        }

	    }
	    maxocc = max(maxocc,currentocc);
	}
	return maxocc;
}
