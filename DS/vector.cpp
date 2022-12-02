class my_vector{
   public:
    int sz=0;
    int *arr= new int[1];
    int capacity=1;

    void cap(){
        capacity *=2;
        int *temp = new int [capacity];
        for(int i=0;i<sz;i++){
            temp[i]=arr[i];
        }
        delete[]arr;
        arr = temp;
    }
    my_vector(int n=0 , int x=0)
    {
        while(n>capacity) cap();
        sz=n;
        for(int i=0 ; i<n ; i++)
           arr[i]=x;
    }

    void push_Back(int x){
        if(sz+1 >= capacity) cap();
        arr[sz]=x;
        sz++;
    }

    void pop_Back()
    {
        sz--;
    }
    void Clear()
    {
        sz=0;
    }
    void Erase (int x)
    {
        for(int i=x ; i<sz-1 ;i++)
        {
            arr[i]=arr[i+1];
        }
        sz--;
    }
    void Erase (int x ,int y)
    {
        for(int i=0 ; i<y-x+1&& y+i+1<sz ;i++)
        {
            arr[x+i]=arr[y+i+1];
        }
        sz-=(y-x+1);
    }

    int Size(){
        return sz;
    }

    int * Begin(){
        return arr;
    }
    int * END(){
        return arr+sz;
    }
    void print(){
      for(int i=0 ; i<sz; i++) cout<<arr[i] <<' ';
      cout<<'\n';
    }
    void operator =(my_vector a){
        for(int i=0;i<a.Size();i++){
            this->push_Back(a.arr[i]);
        }
    }
    void operator =(vector <int>a){
        for(int i=0;i<a.size();i++){
            this->push_Back(a[i]);
        }
    }
    int operator[](int i){
        return arr[i];
    }
    void Emplace(int*p,int val)
    {
        while(sz+1>=capacity) cap();
        for(int i= sz ; i>p-Begin();i--)
        {
           arr[i]=arr[i-1];
        }
        arr[p-Begin()]=val;
        sz++;

    }
};
**************************************************************