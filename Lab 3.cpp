#include <iostream>
using namespace std;

void create(int ptr[], int size) {
    cout << "Enter Values" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Value " << i << " = ";
        cin >> ptr[i];
    }
}

void read(int ptr[], int size) {
    cout << "Displaying Values" << endl;
    for (int i = 0; i < size; i++) { 
        cout << "Value " << i << " = " << ptr[i] << endl;
    }
}

void update(int ptr[], int size) {
    int index;
    int value;
    cout << "Enter Index to Update: ";
    cin >> index;
    if (index >= 0 && index < size) {
        cout << "Enter New Value: ";
        cin >> value;
        ptr[index] = value;
    } else {
        cout << "Invalid Index" << endl;
    }
}

void del(int ptr[], int &size) { 
    int index;
    cout << "Enter Index to Delete: ";
    cin >> index;
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            ptr[i] = ptr[i + 1]; 
        }
        size--;  
    } else {
        cout << "Invalid Index" << endl;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *ptr = new int[size];

    int ch;
    bool exit = false;

    while (!exit) {
        cout << "\nWould you like to:" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create(ptr, size);
                break;
            case 2:
                read(ptr, size);
                break;
            case 3:
                update(ptr, size);
                break;
            case 4:
                del(ptr, size);
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

   
    delete[] ptr;


//	int row;
//	int column;
//	cout<<"Enter rows";
//	cin>>row;
//	cout<<"Enter Column";
//	cin>>column;
//	int **ptr=new int *[row];
//	for(int i=0;i<row;i++){
//		ptr[i]=new int[column];
//		
//	}
//	cout<<"Enter Values"<<endl;
//	for(int i=0;i<row;i++){
//		for(int j=0;j<column;j++){
//	        cin>>ptr[i][j];
//        }  cout<<endl;
//	}
//	cout<<"Displaying Values"<<endl;
//	for(int i=0;i<row;i++){
//		for(int j=0;j<column;j++){
//	        cout<<ptr[i][j]<<" ";
//        }
//        cout<<endl;
//	}
//		

//	int max=0;
//	int min=100;
//	for(int i=0;i<=size;i++){
//	if(arr[i]>=max){
//	max=arr[i];
//	}
//	if(arr[i]<=min){
//	min=arr[i];
//	}}
//	cout<<endl;
//	cout<<"Maximum Number = "<<max<<endl;
//	cout<<"Minimum Number = "<<min<<endl;
return 0;
}
