#include <iostream>

using namespace std;

int n, x, y, v[20], v2[20], st, dr, cnt = 1, temp[20];

void start() //interfata de inceput
{
    cout << "Choose one from the next sorting algorithms: " << endl;
    cout << "1.Bubble Sort" << endl;
    cout << "2.Selection Sort " << endl;
    cout << "3.Insertion Sort " << endl;
    cout << "4.Merging Vectors " <<endl;
    cout << "5.Merge Sort " << endl;
    cout << "6.Quick Sort " << endl;
    cout << "7.Heap Sort " << endl;
    cout << "Choose a number from 1 to 7 " << endl;


}
void variabile() // citire termeni de sortat si numarul lor
{
    cout << "Enter the number of elements for the vector you want to sort (the number must be between 2 and 15): ";
    while(x < 2 || x > 15)
    {
        cin >> x;
    }
    cout << endl;
    cout<<"Enter the elements of the vector: " << endl;
    for(int i = 0; i < x; i++){
        cout << "v["<<i<<"]= ";
        cin >> v[i];
    }

}
void variabile_qk_mg() // citire termeni de sortat si numarul lor pentru quick si merge sort
{
    cout << "Enter the number of elements for the vector you want to sort (the number must be between 2 and 15): ";
    while(dr < 2 || dr > 15)
    {
        cin >> dr;
    }
    cout << endl;
    cout<<"Enter the elements of the vector: " << endl;
    for(int i = 0; i < dr; i++){
        cout << "v["<<i<<"]= ";
        cin >> v[i];
    }

}
void variabile_inter() // citire termeni de sortat si numarul lor pentru interclasare
{
    cout << "Enter the number of elements for the first vector you want to merge (the number must be between 2 and 15): ";
    while(x < 2 || x > 15)
    {
        cin >> x;
    }
    cout << endl;
    cout<<"Enter the elements of the vector (the elements must be sorted in ascending order): " << endl;
    for(int i = 0; i < x; i++){
        cout << "v1["<<i<<"]= ";
        cin >> v[i];
    }
    cout << "Enter the number of elements for the second vector you want to merge (the number must be between 2 and 15): ";
    while(y < 2 || y > 15)
    {
        cin >> y;
    }
    cout << endl;
    cout<<"Enter the elements of the vector (the elements must be sorted in ascending order): " << endl;
    for(int i = 0; i < y; i++){
        cout << "v2["<<i<<"]= ";
        cin >> v2[i];
    }
}
void heapify(int v[], int x, int i) //subprogram in legatura cu heapsort-ul #line 267
{
    int mx = i, st = 2 * i + 1, dr = 2 * i + 2;
    if (st < x && v[st] > v[mx])
        mx = st;
    if (dr < x && v[dr] > v[mx])
        mx = dr;
    if(mx != i)
    {
        swap(v[i], v[mx]);
        heapify(v, x, mx);
    }
}


void bubble_sort(int x, int v[])
{
    bool schimbat;
    int cnt = 1;
    for (int i = 0; i < x - 1; i++) {
        schimbat = false;
        for (int j = 0; j < x - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                schimbat = true;
            }
        }
        if (schimbat == false)
            break;
        cout <<"Step " << cnt << " : ";
        for(int ind = 0; ind < x; ind++)
            cout << v[ind]<<" ";

        cout<<endl;
        cnt++;

    }
}

void selection_sort(int x, int v[])
{

    int i, j, minim, cnt = 1;
    for (i = 0; i < x - 1; i++)
    {
        minim = i;
        for (j = i + 1; j < x; j++)
        {
            if (v[j] < v[minim])
                minim = j;
        }


        if (minim != i)
            swap(v[minim], v[i]);

        cout <<"Step " << cnt << " : ";
        for(int ind = 0; ind < x; ind++){
        cout << v[ind]<<" ";
        }
        cout<<endl;
        cnt++;
    }

}

void insertion_sort(int x, int v[])
{
    int i, aux, j, cnt = 1;
    for (i = 1; i < x; i++)
    {
        aux = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = aux;

        cout <<"Step " << cnt << " : ";
        for(int ind = 0; ind < x; ind++){
        cout << v[ind]<<" ";
        }
        cout<<endl;
        cnt++;
    }
}
void merging_vectors(int x, int y, int v1[], int v2[])
{
    int i = 0 , j = 0;
    int v3[40], ind = 0;
    while(i < x && j < y)
        if(v1[i] < v2[j])
        {
            v3[ind] = v1[i];
            i++;
            ind++;
        }
        else
        {
            v3[ind] = v2[j];
            j++;
            ind++;
        }
    while(i < x)
    {
        v3[ind] = v1[i];
        i++;
        ind++;
    }

    while(j < y)
    {
        v3[ind] = v2[j];
        j++;
        ind++;
    }
    cout << "The merged vector is: ";
    for(ind = 0; ind < x + y; ind++)
        cout << v3[ind] << " ";

}
void merge_sort(int v[], int st, int dr)
{
    if (st < dr) {
        int m = (st + dr) / 2;
        merge_sort(v, st , m);
        merge_sort(v, m + 1 , dr);
        int i = st, j = m + 1, k = 0;
        while (i <= m && j <= dr)
            if (v[i] < v[j])
                temp[++k] = v[i++];
            else
                temp[++k] = v[j++];
        while (i <= m)
            temp[++k] = v[i++];
        while (j <= dr)
            temp[++k] = v[j++];
        for (i = st, j = 1; i <= dr; i++, j++)
            v[i] = temp[j];
    }
    cout <<"Step " << cnt << " : ";
        for(int ind = 1; ind <= dr; ind++)
            cout << v[ind]<<" ";

        cout<<endl;
        cnt++;

}

void quick_sort(int v[], int st, int dr)
{

	if(st < dr)
	{

		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quick_sort(v, st , i - 1);
		quick_sort(v, i + 1 , dr);
		/*for(int ind = 1; ind <= dr; ind++)
            cout << v[ind]<<" ";*/

	}
	cout <<"Step " << cnt << " : ";
        for(int ind = 1; ind <= dr; ind++)
            cout << v[ind]<<" ";

        cout<<endl;
        cnt++;

}

void heap_sort(int v[], int x)
{
    for(int i = x / 2 - 1; i >= 0; i--)
        heapify(v, x, i);
    for(int i = x - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0); // #line 76
        cout <<"Step " << cnt << " : ";
        for(int ind = 0; ind < x; ind++){
        cout << v[ind]<<" ";
        }
        cout<<endl;
        cnt++;

    }

}

void selector(int n) //case selector in care se alege tipul de sortare
{
    cin >> n;
    cout << endl;
    switch (n) {
    case 1:
        cout<<"You have chosen Bubble Sort" << endl;
        variabile();  //#line 21
        bubble_sort(x, v);  //#line 91
        break;
    case 2:
        cout<<"You have chosen Selection Sort" << endl;
        variabile();  //#line 21
        selection_sort(x, v);  //#line 115
        break;
    case 3:
        cout<<"You have chosen Insertion Sort" << endl;
        variabile();  //#line 21
        insertion_sort(x, v);  //#line 142
        break;
    case 4:
        cout<<"You have chosen Merging Vectors" << endl;
        variabile_inter();  //#line 51
        merging_vectors(x, y, v, v2);  //#line 166
        break;
    case 5:
        cout<<"You have chosen Merge Sort" << endl;
        variabile_qk_mg();  //#line 36
        merge_sort(v, st, dr);  //#line 201
        break;
    case 6:
        cout<<"You have chosen Quick Sort" << endl;
        variabile_qk_mg();  //#line 36
        quick_sort(v, st, dr);  //#line 229
        break;
    case 7:
        cout<<"You have chosen Heap Sort" << endl;
        variabile();  //#line 21
        heap_sort(v, x);  //#line 267
        break;
    default:
        cout << "The entered number must be between 1 and 7!" << endl << endl;
        cout << "Enter a number between 1 and 7: ";
        selector(n); //#line 286
        break;
    }
}


int main()
{
    start();  //#line 7
    selector(n);  //#line 286
    cout << "Press any key to end the program"<<endl;
    int endline; cin >> endline;

    return 0;
}
