bool isPalindrome(int x) {
    long temp=x, rem=0, pal=0;
    while(temp>0){
      rem=temp%10;
      pal=pal*10+rem;
      temp=temp/10;
    }
    if(x==pal) return 1;
    return 0;
}