#include <List>
#include <QCoreApplication>
#include <QFile>
#include <QList>
#include <iostream>
#include <windows.h>
using namespace std;


QByteArray fileData;


void ReadFromFile(const char* fileName, unsigned int* buff) {
    FILE *f;
    f = fopen(fileName, "r");
    if(f == nullptr){
        return;
    }
    char i;
    do {
        i = getc(f);
        if (i != EOF) {
            buff[i]++;
        }
    } while (i != EOF);
    fclose(f);
}

void task1 () { //task1
    unsigned int buff[255] = {0};
    ReadFromFile("C:\\inputfile.txt",buff);

    QFile file("C:\\1.txt"); //writetofile
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << buff;
        file.close();
}


char binNumber[32]; //task2
void perevod(int ar) {
    memset(binNumber, 0x00, 32 * sizeof(int));

    for (int i = 0; i < 32; i++) {
        binNumber[i] = (ar & 1 << i) ? '1' : '0';
    }
}
void task2(){
    int ar;
    cout << "Введите число: ";
    cin >> ar;
    perevod(ar);
    qDebug() << binNumber << "\n";
    cout << "Сохранено в C:\\2.txt" << endl;

}
void WriteToFile() {
    QFile file("C:\\2.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << binNumber;
        file.close();
}

QList<float> getAver(int* ar, int n, int m) { //task5
    QList<float> Aver;

    for (int i = 0; i < n; i++)
    {
        float temp = 0;
        for (int j = 0; j < m; j++)
        {
             temp += ar[(i * n) + j] / (float)m;
        }

        Aver.append(temp);
    }

    return Aver;
}

void task5() {
    cout << "введите размеры массива (до 10)" << endl;
    int n, m;
    cin >> n >> m;
    int ar[100];
    cout <<"заполните массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           cin >> ar[(i * n) + j];

        }
    }
    int* p = ar;

    qDebug() << getAver(p, n, m);
}



int main(int argc, char* argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    int vibor;
    cout << "Введите номер задания: ";
    cin >> vibor;

    switch(vibor)
    {
        case 2:
            task2();
            WriteToFile();
        break;

        case 5:
            task5();
        break;
        case 1:
            task1();

        break;

    }

}
