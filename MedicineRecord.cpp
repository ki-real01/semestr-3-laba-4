#include "MedicineRecord.h"

MedicineRecord::MedicineRecord(const char* name, int day) : day(day), dosagePerDay(CntPlans) 
{
    if (name == nullptr || strlen(name) == 0) 
    {
        throw invalid_argument("������");
    }

    medicineName = new char[strlen(name) + 1];
    strncpy_s(medicineName, strlen(name) + 1, name, _TRUNCATE);

    for (int i = 0; i < CntPlans; i++) 
    {
        plan[i] = false;
        actual[i] = false;
    }
}

MedicineRecord::MedicineRecord(const MedicineRecord& other, bool copyPlan) : day(other.day + 1), dosagePerDay(CntPlans) 
{
    medicineName = new char[strlen(other.medicineName) + 1];
    strncpy_s(medicineName, strlen(other.medicineName) + 1, other.medicineName, _TRUNCATE);

    for (int i = 0; i < CntPlans; i++) 
    {
        actual[i] = false;

        if (copyPlan) 
        {
            plan[i] = other.plan[i];
        }
        else 
        {
            plan[i] = false;
        }
    }
}

MedicineRecord::~MedicineRecord() 
{
    delete[] medicineName;
}

const char* MedicineRecord::getMedicineName() const
{
    return medicineName;
}

int MedicineRecord::getDay() const 
{
    return day;
}

void MedicineRecord::printMedicineInfo() const 
{
    cout << "���������: " << medicineName << endl;
    cout << "���� ������: " << day << endl << endl;
    cout << "���� ������: " << endl;
    for (int i = 0; i < CntPlans; i++) 
    {
        cout << (plan[i] ? "��" : "���") << " ";
    }
    cout << endl;
    cout << endl << "������� ������: " << endl;
    for (int i = 0; i < CntPlans; i++) {
        cout << (actual[i] ? "��" : "���") << " ";
    }
    cout << endl;
}

void MedicineRecord::setPlan(TimeOfDay timeOfDay) 
{
    if (timeOfDay >= MORNING && timeOfDay <= NIGHT) 
    {
        plan[timeOfDay] = true;
    }
}

void MedicineRecord::takeMedicine(TimeOfDay timeOfDay) 
{
    if (timeOfDay >= MORNING && timeOfDay <= NIGHT)
    {
        actual[timeOfDay] = true;
    }
}

bool MedicineRecord::planMatchesActual() const 
{
    for (int i = 0; i < CntPlans; i++) 
    {
        if (plan[i] != actual[i]) 
        {
            return false;
        }
    }
    return true;
}

void MedicineRecord::operator[](TimeOfDay timeOfDay) 
{
    if (timeOfDay >= MORNING && timeOfDay <= NIGHT)
    {
        actual[timeOfDay] = true;
    }
}

bool MedicineRecord::takeMedicineAt(TimeOfDay timeOfDay) const
{
    if (timeOfDay >= MORNING && timeOfDay <= NIGHT)
    {
        for (int i = 0; i < CntPlans; i++)
            return !plan[i] || (plan[i] && actual[timeOfDay]);
    }
    cout << endl << "Принимать НЕ нужно" << endl;
    return false;
}

ostream& operator<<(ostream& out, const MedicineRecord& record) 
{
    out << "���������: " << record.medicineName << endl;
    out << "���� ������: " << record.day << endl << endl;

    out << "���� ������: " << endl;
    for (int i = 0; i < MedicineRecord::CntPlans; i++) 
    {
        out << (record.plan[i] ? "��" : "���") << " ";
    }

    out << endl;

    out << endl << "������� ������: " << endl;
    for (int i = 0; i < MedicineRecord::CntPlans; i++) 
    {
        out << (record.actual[i] ? "��" : "���") << " ";
    }

    out << endl;

    return out;
}
