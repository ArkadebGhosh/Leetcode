int tour(petrolPump p[],int n)
    {
       //Your code here
       int petrol = 0; //
       int start = 0, ptr2 = 0;
       int ans = -1;
       int minPetrol = 0; //min petrol to start from zero
       for(int i  = 0; i<n; i++) {
           petrol += (p[i].petrol - p[i].distance);
           if(petrol < 0) {
               minPetrol += (-petrol);
               petrol = 0;
           }
       }
       
       if(minPetrol == 0)
       return 0;
       petrol = 0;
       for(int i = 0; i<n; i++) {
           petrol += (p[i].petrol - p[i].distance);
           while(petrol < 0 || (i == n-1 && petrol < minPetrol)) {
               petrol -= (p[start].petrol - p[start].distance);
               start++;
           }
       }
       if(start==n)
       return -1;
       else if(minPetrol > petrol)
       return -1;
       if(start<n && petrol >= minPetrol)
       return start;
       return -1;
    }
