/* Визначити абстрактний тип «телефон» (назва, фірма, ціна). 
Визначити 2 похідні від нього типи: «мобільний телефон»(колір, об’єм пам’яті ),
«радіотелефон» (радіус дії, наявність автовідповідача ).   
У двох текстових файлах задано дані про телефони двох різних фірм. Зчитати ці дані в один масив  і вивести у текстовий файл:
 1)всі телефони, посортовані за ціною із зазначенням загальної суми; 
 2) радіотелефони з автовідповідачем  */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;



class Telephone
{
  protected:
    string name;
    string firm;
    int price;

  public:
    Telephone(): name(" "), firm(" "), price(0) {}
    Telephone(string n, string f, float p): name(n), firm(f), price(p) {}

    virtual void input(istream &is)
    {
      is >> name >> firm>> price;
    }

    friend istream &operator>>(istream &is, Telephone &telephone)
    {
      telephone.input(is);
      return is;
    }

    virtual void output(ostream &os)
    {
      os << "Name: " << name<<endl;
       os<< "Firm: " <<firm<<endl ;
       os<< "Price: " << price<<endl;
    }

    friend ostream &operator<<(ostream &os, Telephone &telephone)
    {
      telephone.output(os);
      return os;
    }

    bool operator<(const Telephone &telephone)
    {
      return price < telephone.price;
    }

    int getPrice() { return price; }

    virtual int getAuto_Answer() { return -1; }
};

class MobilePhone : public Telephone
{
  protected:
    string color;
    int memory;

  public:
    void input(istream &is)
    {
      Telephone::input(is);
      is >> color >> memory;
    }

    void output(ostream &os)
    {
      Telephone::output(os);
      os << "Color: " << color << endl;
      os<<"Memory size: " << memory << endl<<endl;
    }
};

class RadioPhone : public Telephone
{
  protected:
    int radius;
    bool auto_answer;

  public:
    void input(istream &is)
    {
      Telephone::input(is);
      is >> radius >> auto_answer;
    }

    void output(ostream &os)
    {
      Telephone::output(os);
      os << "Active radius: " << radius <<endl;
      os<< "Auto answer: " << auto_answer << endl<<endl;
    }

    int getAuto_Answer() { return auto_answer; }
};

int main()
{
  vector<Telephone*> arr;
  ifstream file1("input.txt");
  ofstream file2("output.txt");

  int sum = 0;

  while(!file1.eof())
  {
    Telephone* temp;
    int n;
    file1 >> n;

    if(n == 1)
      temp = new MobilePhone();
    else
    if(n == 2)
      temp = new RadioPhone();
    
    temp->input(file1);
    arr.push_back(temp);
    sum += temp->getPrice();
  }
  
  sort(arr.begin(), arr.end(),[](Telephone* t1, Telephone* t2) { return *t1 < *t2; });

  file2 << "All phones, sorted by price:" << endl;
  for(int i = 0; i < arr.size(); i++)
    arr[i]->output(file2);
  file2 << "Total sum: " << sum << endl << endl;

  file2 << "Radio phones with auto answer:" << endl;
  for(int i = 0; i < arr.size(); i++)
  {
    if(arr[i]->getAuto_Answer() == 1)
      arr[i]->output(file2);
  }

  file1.close();
  file2.close();
}