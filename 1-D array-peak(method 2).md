In this question we are using second approach to find the first discoverable peak of the 1-D array
We are calculating the mid element of the array by the formula;
mid=(high +low)/2;where high is the last element of the array and the low is the first element of the array
If the mid element is both greater than the mid-1 element and the mid+1 element than the peak is the mid element
If the mid-1 element is greater than the mid element than the high will be shifted to mid -1 element and low to the first element and again the peak will be found
In case the mid+1 element is greater than the mid element than the low will be shifted to the mid+1 element and the high to the last element and again the peak will be found
