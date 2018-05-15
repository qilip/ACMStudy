#include <cstdio>
#include <algorithm>

using namespace std;

struct Heap {
    int arr[100005];
    int size;

    int top(){
        return arr[1];
    }
    void push(int x){
        arr[++size] = x;
        for(int cur=size;cur>1;cur/=2){
            if(arr[cur]>arr[cur/2])
                swap(arr[cur], arr[cur/2]);
            else
                break;
        }
    }

    void pop(void){
        arr[1] = arr[size--];
        int child;
        for(int cur=1;cur*2 <= size; cur = child){
            if(cur*2+1 <= size && arr[cur*2+1]>arr[cur*2])
                child = cur*2+1;
            else
                child = cur*2;
            if(arr[cur]<arr[child])
                swap(arr[cur], arr[child]);
            else
                break;
        }
    }

    int siz(){
        return size;
    }

    Heap() {
        size = 0;
    }
};

Heap heap;

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 0){
            if(heap.siz()==0){
                printf("0\n");
            }else{
                printf("%d\n", heap.top());
                heap.pop();
            }
        }else{
            heap.push(tmp);
        }
    }
    return 0;
}
