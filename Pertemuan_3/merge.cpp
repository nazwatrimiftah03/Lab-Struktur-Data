#include <iostream>  // library untuk input  dan output
#include <vector> // library untuk struktur data vector
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang sudah diurutkan
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;   // jumlah elemen pada subarray kiri
    int n2 = right - mid;     // jumlah elemen pada subarray kanan


    vector<int> L(n1), R(n2); // membuat dua vector sementara untuk menyimpan subarray kiri dan kanan

    // Menyalin data dari arr ke subarray kiri (L)
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
     // Menyalin data dari arr ke subarray kanan (R)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    int i = 0;     // indeks untuk subarray kiri (L)
    int j = 0;     // indeks untuk subarray kanan (R)
    int k = left;  // indeks awal untuk array utama (arr)

    // Menggabungkan kembali kedua subarray ke dalam arr dengan urutan yang benar
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {    // jika elemen kiri lebih kecil atau sama dengan kanan
            arr[k] = L[i];     // masukkan elemen dari kiri
            i++;               // pindah ke elemen berikutnya di kiri
        } else {               // jika elemen kanan lebih kecil
            arr[k] = R[j];     // masukkan elemen dari kanan
            j++;               // pindah ke elemen berikutnya di kanan
        }
        k++; // pindah ke indeks berikutnya di array utama
    }

    // Jika masih ada sisa elemen di subarray kiri, masukkan semuanya ke arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa elemen di subarray kanan, masukkan semuanya ke arr
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {

    if (left >= right) // kondisi berhenti (hanya satu elemen)
        return;

    int mid = left + (right - left) / 2; // menghitung titik tengah array

    mergeSort(arr, left, mid);      // mengurutkan bagian kiri secara rekursif
    mergeSort(arr, mid + 1, right); // mengurutkan bagian kanan secara rekursif

    merge(arr, left, mid, right);   // menggabungkan kedua bagian yang sudah diurutkan
}


// Fungsi untuk mencetak isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) { // perulangan untuk menampilkan semua elemen
        cout << arr[i] << " ";             // menampilkan elemen ke-i diikuti spasi
    }
    cout << endl; // baris baru setelah seluruh elemen dicetak
}

int main() {
    int n; // variabel untuk menyimpan jumlah elemen
    cout << "Masukkan jumlah elemen data: "; // meminta pengguna memasukkan jumlah data
    cin >> n; // membaca jumlah elemen dari input

    vector<int> data(n); // membuat vector 'data' dengan ukuran n
    cout << "Masukkan elemen-elemen data: "; // meminta pengguna memasukkan elemen-elemen
    for (int i = 0; i < n; i++) { // perulangan sebanyak n kali
        cin >> data[i]; // membaca setiap elemen ke dalam vector
    }

    cout << "Array sebelum diurutkan: "; // menampilkan array sebelum diurutkan
    printArray(data); // memanggil fungsi printArray untuk menampilkan data

    mergeSort(data, 0, n - 1); // memanggil fungsi mergeSort untuk mengurutkan seluruh array

    cout << "Array setelah diurutkan: "; // menampilkan hasil setelah diurutkan
    printArray(data); // menampilkan array yang telah diurutkan

    return 0; // mengakhiri program dengan status sukses
}