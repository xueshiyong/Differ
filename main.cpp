#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Hematrix(int n){
    int i = 0;
    int j = 0;
    int index = 1;
    int temp;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int ncount = n - 1;
    while (ncount >= 1){

        // 右
        temp = ncount;
        while (temp > 0){
            arr[i][j] = index;
            j++;
            index++;
            temp--;
        }
        cout <<"i: " << i << " j: " << j << endl;

        // 下
        temp = ncount;
        while (temp > 0){
            arr[i][j] = index;
            i++;
            index++;
            temp--;
        }
        cout <<"i: " << i << " j: " << j << endl;

        // 上
        temp = ncount;
        while (temp > 0){
            arr[i][j] = index;
            j--;
            index++;
            temp--;
        }
        cout <<"i: " << i << " j: " << j << endl;

        //下
        temp = ncount;
        while (temp > 0){
            arr[i][j] = index;
            i--;
            index++;
            temp--;
        }
        cout <<"i: " << i << " j: " << j << endl;

        i++;
        j++; // 移动起始点
        ncount -= 2; // 旋转一周，就会减掉2
    }
    if (n % 2 != 0){
        arr[n/2][n/2] = n * n;
    }

    return arr;
}

bool BiSearch(vector<int> arr, int val){
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    if (arr[0] == val or arr[arr.size()-1] == val){
        return true;
    }

    while (left < right - 1){
        mid = (left + right) / 2;
        if (arr[mid] <  val){
            left = mid;
        }
        else if (arr[mid] > val){
            right = mid;
        }
        else{
            return true;
        }
    }
    return false;

}

int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    for (int i = 0; i < 14; i++){
        cout << BiSearch(arr, i+1) << endl;
    }
}