#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Major { KI, INF, MATH, PHYSICS, ART };
string majorStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student
{
    string prizv;
    unsigned int kurs;
    Major major;
    int physics;
    int math;
    int IT;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CountGoodGrades(Student* p, const int N);
double CalculatePercentGoodPhysicsMath(Student* p, const int N);

int main()
{
    
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    CountGoodGrades(p, N);

    double percent = CalculatePercentGoodPhysicsMath(p, N);
    cout << "������� ��������, �� �������� '5' � � ������ � � ����������: " << fixed << setprecision(2) << percent << "%" << endl;

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int major;

    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get(); // ������� ����� ��������� � �� ����������� �������
        cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " ����: "; cin >> p[i].kurs;
        cout << " ������������ (0 - ��������� �����, 1 -����������� , 2 -���������� �� �������� , 3 -Գ���� �� �����������, 4 -������� ��������): ";
        cin >> major;
        p[i].major = static_cast<Major>(major);
        cout << " ������ "; cin >> p[i].physics;
        cout << " ���������� "; cin >> p[i].math;
        cout << " ����������� "; cin >> p[i].IT;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "=========================================================================================="
        << endl;
    cout << "|  � |   �������   | ���� | ������������          | Գ���� | ���������� | �����������  |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(23) << left << majorStr[p[i].major];
        cout << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math
            << "| " << setw(12) << right << p[i].IT;
        cout << " |" << endl;
    }
    cout << "=========================================================================================="
        << endl;
    cout << endl;
}

void CountGoodGrades(Student* p, const int N)
{
    int countPhysics = 0;
    int countMath = 0;
    int countIT = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 4) {
            countPhysics++;
        }

        if (p[i].math == 4) {
            countMath++;
        }

        if (p[i].IT == 4) {
            countIT++;
        }
    }

    cout << "==============================================" << endl;
    cout << "ʳ������ ������ '�����' � ������� ��������:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Գ����: " << countPhysics << " | ����������: " << countMath << " | �����������: " << countIT << endl;
    cout << "==============================================" << endl;
}

double CalculatePercentGoodPhysicsMath(Student* p, const int N)
{
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 5 && p[i].math == 5) {
            k++;
        }
    }

    return 100.0 * k / N;
}
