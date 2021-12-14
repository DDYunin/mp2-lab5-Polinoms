#include "Polinom.h"

bool fileIsExist = false;

void Polinom::CollectTerms(TList<Monom>& nlist)
{
    for (int i = 0; i < nlist.size(); i++) {
        for (int j = i; j < nlist.size(); j++) {
            if ((nlist[i] == nlist[j]) && (i != j)) {
                Monom m = nlist[i] + nlist[j];
                nlist[i] = m;
                nlist.removeAt(j);
                j--;
            }
        }
    }
}

Monom Polinom::CreateMonomWithoutVars(const string& str)
{
    Monom temp;
    string s = "";
    for (size_t i = 0; i < str.size() ; i++)
        s += str[i];
    double coeff = stod(s);
    temp.coefficient = coeff;
    return temp;
}

Monom Polinom::CreateMonomWithOneVar(const string& str)
{
    Monom temp;
    string s = "";
    char varName = '0';
    for (size_t i = 0; i < str.size(); i++) {
        if ((str[i] == 'x') || (str[i] == 'y') || (str[i] == 'z')) {
            varName = str[i];
            double coeff = stod(s);
            temp.coefficient = coeff;
            s = "";
            continue;
        }
        s += str[i];
    }
    int value = stoi(s);
    DetermineVarAndFillMonom(temp, varName, value);
    return temp;
}

Monom Polinom::CreateMonomWithTwoVars(const string& str)
{
    Monom temp;
    string s = "";
    char varName = '0';
    short numVars = 1;
    for (int i = 0; i < str.size(); i++) {
        if ((numVars == 1) && ((str[i] == 'x') || (str[i] == 'y'))) {
            varName = str[i];
            double coeff = stod(s);
            temp.coefficient = coeff;
            numVars++;
            s = "";
            continue;
        }
        if ((numVars == 2) && ((str[i] == 'y') || (str[i] == 'z')))
        {
            int value = stoi(s); 
            DetermineVarAndFillMonom(temp, varName, value);
            varName = str[i];
            s = "";
            continue;
        }
        s += str[i];
    }
    int value = stoi(s);
    DetermineVarAndFillMonom(temp, varName, value);
    return temp;
}

Monom Polinom::CreateMonomWithThreeVars(const string& str)
{
    Monom temp;
    string s = "";
    char varName = '0';
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'x') {
            varName = str[i];
            double coeff = stod(s);
            temp.coefficient = coeff;
            s = "";
            continue;
        }
        if (str[i] == 'y') {
            int value = stoi(s);
            DetermineVarAndFillMonom(temp, varName, value);
            varName = str[i];
            s = "";
            continue;
        }
        if (str[i] == 'z') {
            int value = stoi(s);
            DetermineVarAndFillMonom(temp, varName, value);
            varName = str[i];
            s = "";
            continue;
        }
        s += str[i];
    }
    int value = stoi(s);
    DetermineVarAndFillMonom(temp, varName, value);
    return temp;
}

double Polinom::CalculateNumInPow(double num, int pow, char symbol)
{
    double number = 1;
    switch (symbol)
    {
    case 'x':
        for (int i = 1; i <= pow; i++)
            number *= num;
        break;
    case 'y':
        for (int i = 1; i <= pow; i++)
            number *= num;
        break;
    case 'z':
        for (int i = 1; i <= pow; i++)
            number *= num;
        break;
    }
    return number;
}

void Polinom::TransformString(string& str)
{
    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == '-')
        {
            str.insert(i,"+");
            i++;
        }
    }
}

string Polinom::CreateStringFromMonom(const Monom& mon)
{
    string temp = "";
    vector<char> namevars;
    int numvars = FindNumVars(mon, namevars);
    switch (numvars)
    {
    case 0:
        CreateStringWithoutVars(temp, mon);
        break;
    case 1:
        CreateStringWithoutVars(temp, mon);
        CreateStringWithOneVars(temp, mon, namevars[0]);
        break;
    case 2:
        CreateStringWithoutVars(temp, mon);
        CreateStringWithOneVars(temp, mon, namevars[0]);
        CreateStringWithOneVars(temp, mon, namevars[1]);
        break;
    case 3:
        CreateStringWithoutVars(temp, mon);
        CreateStringWithOneVars(temp, mon, namevars[0]);
        CreateStringWithOneVars(temp, mon, namevars[1]);
        CreateStringWithOneVars(temp, mon, namevars[2]);
        break;
    default:
        break;
    }
    return temp;
}

int Polinom::FindNumVars(const Monom& mon, vector<char>& v)
{
    int numvars = 0;
    if (mon.coefficient != 0) {
        if (mon.degreeX != 0){
            numvars++;
            v.push_back('x');
        }
        if (mon.degreeY != 0) {
            numvars++;
            v.push_back('y');
        }
        if (mon.degreeZ != 0) {
            numvars++;
            v.push_back('z');
        }
    }
    return numvars;
}

void Polinom::CreateStringWithoutVars(string& str, const Monom& mon)
{
    string s = to_string(mon.coefficient);
    //cout << endl << s << endl;
    if (s[s.size() - 1] == '0')
        for (size_t i = s.size() - 1; s[i] == '0'; i--)
            s.erase(i, 1);

    if ((s[s.size() - 1] == ',') || (s[s.size() - 1] == '.'))
        s.erase(s.size() - 1, 1);

    //cout << "s=" << s << "\n";
    str = s;
}

void Polinom::CreateStringWithOneVars(string& str, const Monom& mon, char name_var)
{
    if (name_var == 'x') {
        str += name_var;
        str += to_string(mon.degreeX);
    }
    if (name_var == 'y') {
        str += name_var;
        str += to_string(mon.degreeY);
    }
    if (name_var == 'z') {
        str += name_var;
        str += to_string(mon.degreeZ);
    }
}

void Polinom::DeleteNullCoefficients(TList<Monom>& nlist)
{
    for (size_t i = 0; i < nlist.size(); i++)
    {
        if (nlist[i].coefficient == 0) {
            nlist.removeAt(i);
            i--;
        }
    }
}

void Polinom::AddNull(TList<Monom>& nlist)
{
    if (nlist.empty()) {
        Monom m;
        nlist.push_back(m);
    }
}

void Polinom::DetermineVarAndFillMonom(Monom& mon, char var_name, int value)
{
    switch (var_name)
    {
    case 'x':
        mon.degreeX = value;
        break;
    case 'y':
        mon.degreeY = value;
        break;
    case 'z':
        mon.degreeZ = value;
        break;
    }
}

void Polinom::CreateList(const string& str)
{
    vector<string> vStr;
    CreateVectorString(vStr, str);
    for (size_t i = 0; i < vStr.size(); i++) {
        Monom mon;
        int numVars = FindNumVars(vStr[i]);
        switch (numVars) {
        case 0:
            mon = CreateMonomWithoutVars(vStr[i]);
            break;
        case 1:
            mon = CreateMonomWithOneVar(vStr[i]);
            break;
        case 2:
            mon = CreateMonomWithTwoVars(vStr[i]);
            break;
        case 3:
            mon = CreateMonomWithThreeVars(vStr[i]);
            break;
        }
        list.push_back(mon);
    }
}


int Polinom::FindNumVars(const string& str)
{
    int numVars = 0;
    for (size_t i = 0; i < str.size(); i++)
        if ((str[i] == 'x')||(str[i] == 'y')||(str[i] == 'z'))
            numVars++;
    return numVars;
}

void Polinom::CreateVectorString(vector<string>& v, const string& str)
{
    int i = 0;
    string temp = "";
    while (str[i] != '!') {
        if (str[i] == '+') {
            v.push_back(temp);
            temp = "";
            i++;
            continue;
        }
        temp += str[i];
        i++;
    }
    v.push_back(temp);
}

Polinom::Polinom(const string& _polinom)
{
    if (_polinom == "")
        throw "Ќе бывает пустого полинома!";
    string str = _polinom;
    TransformString(str);
    str += '!';
    CreateList(str);
    CollectTerms(list);
}

Polinom::Polinom()
{
    //ничего не происходит;
}

Polinom::Polinom(Polinom& _polinom)
{
    list = _polinom.list;
   /* for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }*/
}

Polinom::Polinom(Polinom&& _polinom) noexcept
{
    Swap(list, _polinom.list);
}

void Polinom::Sorted()
{
    //list.print();
    //cout << "=======================";
    //перевести лист в вектор
    vector<Monom> v = list.to_vector();
    //отсортировать вектор по убыванию, а в векторе же есть метод
    sort(v.begin(), v.end());
    //for (int i = 0; i < v.size(); i++)
        //cout << v[i] << endl;
    //cout << "=======================";
    //создать новый лист
    TList<Monom> l(v);
    //l.print();
    l.invert();
    //cout << "=======================";
    //l.print();
    //cout << "=======================";
    //присвоить его
    list = l;
    //list.print();
    //cout << "=======================";
}

string Polinom::ToString()
{
    string temp = "";
    for (size_t i = 0; i < list.size(); i++) {
        temp += CreateStringFromMonom(list[i]);
        if (i == list.size() - 1)
            break;
        if(list[i+1].coefficient >= 0)
            temp += "+";
    }
    return temp;
}

Polinom& Polinom::operator=(Polinom& pl)
{
    if (this == &pl) {
        return *this;
    }
    list = pl.list;
    return *this;
}

Polinom& Polinom::operator=(Polinom&& pl) noexcept
{
    if (this != &pl) {
        Swap(list, pl.list);
    }
    return *this;
}

void Polinom::Print()
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i];
        if (i == list.size() - 1)
            break;
        if (list[i+1].coefficient >= 0)
            cout << "+";
    }
    cout << endl;
}

Polinom& Polinom::operator+=(Polinom& pl)
{
    pl.Sorted();
    for (int i = 0; i < pl.list.size(); i++)
        list.push_front(pl.list[i]);
    CollectTerms(list);
    DeleteNullCoefficients(list);
    AddNull(list);
    this->Sorted();
    return *this;
}

Polinom Polinom::operator+(Polinom& pl)
{
    pl.Sorted();
    this->Sorted();
    TList<Monom> first = list;
    TList<Monom> second = pl.list;
    TList<Monom> nlist;
    for (int i = 0; i < first.size(); i++) {
        bool isplus = false;
        for (int j = 0; j < second.size(); j++) {
            if (first[i] == second[j]) { //чтобы быстрее работало, использую push_front, а не push_back
                Monom temp = first[i] + second[j];
                nlist.push_front(temp);
                second.removeAt(j);
                j--;
                isplus = true;
            }
        }
        if (!isplus) {
            nlist.push_front(first[i]);
            first.removeAt(i);
            i--;
            isplus = false;
        }
    }
    DeleteNullCoefficients(nlist);
    for (int i = 0; i < second.size(); i++) {
        nlist.push_back(second[i]);
        second.removeAt(i);
        i--;
    }
    //ѕровер€ем на пустоту лист, если он пустой, то добавл€ем 0
    AddNull(nlist);
    Polinom npl(nlist);
    npl.Sorted();
    return npl;
}

Polinom& Polinom::operator*=(Polinom& pl)
{
    TList<Monom> nlist;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < pl.list.size(); j++) {
            Monom temp = list[i] * pl.list[j];
            nlist.push_front(temp);
        }
    }
    //привести подобные
    CollectTerms(nlist);
    DeleteNullCoefficients(nlist);
    AddNull(nlist);
    list = nlist;
    this->Sorted();
    return *this;
}

Polinom Polinom::operator*(Polinom& pl)
{
    TList<Monom> nlist;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < pl.list.size(); j++) {
            Monom temp = list[i] * pl.list[j];
            nlist.push_front(temp);
        }
    }
    //привести подобные
    CollectTerms(nlist);
    DeleteNullCoefficients(nlist);
    AddNull(nlist);
    Polinom npl(nlist);
    npl.Sorted();
    return npl;
}

double Polinom::CalculateInPoint(double valueX, double valueY, double valueZ)
{
    double sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += list[i].coefficient * CalculateNumInPow(valueX, list[i].degreeX, 'x') * CalculateNumInPow(valueY, list[i].degreeY, 'y') *
            CalculateNumInPow(valueZ, list[i].degreeZ, 'z');
    }
    return sum;
}

Polinom Polinom::TakeDerivative(char varDerivative)
{
    TList<Monom> nlist = list;
    for (int i = 0; i < nlist.size(); i++)
        nlist[i].Derivative(varDerivative);
    DeleteNullCoefficients(nlist);
    AddNull(nlist);
    Polinom pr(nlist);
    return pr;
}

Polinom Polinom::TakeIntegral(char varIntegration)
{
    TList<Monom> nlist = list;
    for (int i = 0; i < nlist.size(); i++)
        nlist[i].Integrate(varIntegration);
    Polinom pr(nlist);
    return pr;
}

double Polinom::TakeAndCalculateDefiniteIntegral(char varIntegration, double startpointX, double startpointY, double startpointZ, double endpointX, double endpointY, double endpointZ)
{
    Polinom np; 
    np = TakeIntegral(varIntegration);
    double endvalue = np.CalculateInPoint(endpointX,endpointY,endpointZ);
    double startvalue = np.CalculateInPoint(startpointX, startpointY, startpointZ);
    return endvalue - startvalue;
}

void WritePolinomInFile(Polinom& polinom)
{
    if (!fileIsExist) {
        ofstream outf("HistoryOfPolinoms.txt");
        if (!outf)
            throw "ќ нет, HistoryOfPolinoms.txt не может быть открыт дл€ записи!";
        string str = "";
        polinom.Sorted();
        str = polinom.ToString();
        outf << str << endl;
        outf.close();
        fileIsExist = true;
    }
    else {
        ofstream outf("HistoryOfPolinoms.txt", ios::app);
        if (!outf)
            throw "ќ нет, HistoryOfPolinoms.txt не может быть открыт дл€ записи!";
        string str = "";
        polinom.Sorted();
        str = polinom.ToString();
        outf << str << endl;
        outf.close();
    }
    
}

string ReadPolinomFromFile(int num_polinom)
{
    string str;
    ifstream inf("HistoryOfPolinoms.txt");
    if (!inf)
        throw "ќ нет, HistoryOfPolinoms.txt не может быть открыт дл€ чтени€!";
    int countpolinoms = 0;
    while (inf) {
        string strInput;
        getline(inf, strInput);
        countpolinoms++;
    }
    countpolinoms--;
    inf.close();
    inf.open("HistoryOfPolinoms.txt");
    if ((num_polinom > countpolinoms) || (num_polinom < 0))
        throw "ќшибка! “акой строки нет в файле";
    else {
        int i = 0;
        while (1) {
            if (i == num_polinom) {
                getline(inf, str);
                break;
            }
            string strInput;
            getline(inf, strInput);
            i++;
        }
    }
    return str;
}

void PrintPolinomsFromFile()
{
    ifstream inf("HistoryOfPolinoms.txt");
    if (!inf)
        throw "ќ нет, HistoryOfPolinoms.txt не может быть открыт дл€ чтени€!";
    int countpolinoms = 0;
    while (inf) {
        string strInput;
        getline(inf, strInput);
        countpolinoms++;
    }
    countpolinoms--;
    inf.close();
    inf.open("HistoryOfPolinoms.txt");
    if (!inf)
        throw "ќ нет, HistoryOfPolinoms.txt не может быть открыт дл€ чтени€!";
    int i = 0;
    while (i < countpolinoms) {
        cout << i << ") ";
        string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
        i++;
    }
    inf.close();
}
