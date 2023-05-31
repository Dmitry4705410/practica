#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);//��� ����� ��������� 
    SetConsoleOutputCP(1251);//��� ������� ���������
    string a;//������ �����
    string b;//������ �����
    cout << "������� ����� ������ _ ������:";

    //���� ����
    cin>> a >> b;

    //������ ����
    int aVal = a.size();
    int bVal = b.size();
   // cout << aVal << " _ " << bVal << endl; //����� ������� ����

    //�������� ���������� �������
    int** p = new int* [aVal + 1];
    for (int i = 0; i < aVal + 1; i++) {
        p[i] = new int[bVal + 1];
    }
    //���������� ������ ������ � ������� �������
    for (int i = 0; i <= aVal; i++) {
        p[i][0] = i;
    }
    for (int i = 0; i <= bVal; i++) {
        p[0][i] = i;
    }

    // ����������� ������� �� ��������
    int va;
    int vb;
    int vc;
    int vd;
    for (int j = 1; j <= bVal; j++) {
        for (int i = 1; i <= aVal; i++) {
            va = p[i][j - 1] + 1;
            vb = p[i - 1][j] + 1;
            if (a[i - 1] == b[j - 1]) {
                vd = 0;
            }
            else {
                vd = 1; 
            }
            vc = p[i - 1][j - 1] + vd;

            if (va <= vb && va <= vc) {
                p[i][j] = va;
            }
            else if (vb <= va && vb <= vc) {
                p[i][j] = vb;
            }
            else if (vc <= va && vc <= vb) {
                p[i][j] = vc;
            }
        };
    }

    //����� �������
    for (int i = 0; i <= bVal; i++) {
        for (int j = 0; j <= aVal; j++) {
            cout << p[j][i] << " ";
        }
        cout << endl;
    }

    cout << "�����: ����������� " << p[aVal][bVal] << " �����, ����� ���������� " << b << " � " << a;


    //�������� �������
    for (int i = 0; i < aVal + 1; i++) {
        delete p[i];
    }
    delete p;
}