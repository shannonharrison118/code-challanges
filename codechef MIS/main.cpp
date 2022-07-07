#include <iostream>

//functions from slides
int mg(int arr[], int aux[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, inv = 0;
    while (i <= mid && j <= high)
        if (arr[i] <= arr[j])
            aux[k++] = arr[i++];
        else {
            aux[k++] = arr[j++];
            inv += (mid - i + 1);
        }

    for (int j = i; j <= mid; j++) {
        aux[k++] = arr[i++];
    }

    for (int i = low; i <= high; i++)
        arr[i] = aux[i];

    return inv;
}
int ms(int arr[], int aux[], int low, int high) {
    if (high <= low)
        return 0;
    int mid = (low + ((high - low) >> 1));
    int inv = ms(arr, aux, low, mid);
    inv += ms(arr, aux, mid + 1, high);
    inv += mg(arr, aux, low, mid, high);
    return inv;
}

int main() {
    int cases;
    std::cin >> cases;
    while(cases--){
        int size;
        std::cin >> size;
        int arr[size];
        int aux[size];

        for(int i = 0; i < size; i++){
            long long int x;
            std::cin >> x;
            arr[i] = x;
            aux[i] = x;
        }

        int count = ms(arr,aux,0,size-1);

        for(int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n" << count <<"\n";
    }
    return 0;
}
