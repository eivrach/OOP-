#include<iostream>
#include<cmath>
using namespace std;

class BODYMASSINDEX{
	private:
        string name;
		double weight;
		double height;
		int age;
		string gender;
		string health;
		
	public:
		BODYMASSINDEX(){
            name =  " ";
			weight = 0.0;
            height = 0.0;
            age = 0;
            gender = " ";
            health = " ";
		}

        BODYMASSINDEX(string n , double w , double h , int a , string g , string hel){
            name = n;
            weight = w;
            height = h;
            age = a;
            gender = g;
            health = hel;
        }   
        
        double heightInMeters(double height){
		       double hmeters = (height / 100);
			   return hmeters;	
		}

        void INFO() const{
            cout << "NAME : " << name << endl;
            cout << "AGE : " << age << endl;
            cout << "GENDER : " << gender << endl;
            cout << "WEIGHT : " << weight << endl;
            cout << "HEIGHT IN CM : " << height << endl;
            cout << "HEALTH : " << health << endl; 
            cout << endl;
        }

        string getName() const{
            return name;
        }

        double BMICalculator(double weight , double height){
        	double hm = heightInMeters(height);
            double bmi = (weight/(hm * hm));
            return bmi;
        }

        void BMICheck(){
            double pBMI = BMICalculator(weight , height);
            
            if(pBMI < 18.5){
                cout << name << " IS UNDERWEIGHT " << endl;
                cout << "YOU SHOULD EAT MORE VEGETABLES AND FRUIT ????????" << endl; 
                cout << "AND FOCUS ON YOUR HEALTH " << endl;
            }
            else if(pBMI >= 18.5 && pBMI <= 24.9){
                cout << name << " IS HAVING A NORMAL WEIGHT" << endl;
                cout << "MAINTAIN YOUR WEIGHT AND DONT EXCEED FROM YOUR CURRENT WEIGHT " << endl;
            }
            else if(pBMI >= 25 && pBMI <= 29.9){
                cout <<name << " IS OVERWEIGHT" << endl;
                cout << "YOU SHOULD DO MORE EXCERCISE AND EAT HEALTHY ???????????????" << endl;
            }
            else if(pBMI >= 30){
                cout << name << " IS OBESE " << endl;
                cout << "YOU SHOULD DO STRICT EXERCISE AND PROPERLY EAT HEALTHY FOOD ???????????????" << endl;
            }
            cout << endl;
        }
};

int main(){
        string n;
		double w;
		double h;
		int a;
		string g;
		string hel;

        cout << "ENTER NAME : ";
        cin.ignore();
        getline(cin , n);

        cout << "ENTER AGE : ";
        cin >> a;

        cout << "ENTER GENDER (MALE / FEMALE) : ";
        cin.ignore();
        getline(cin , g);

        cout << "ENTER WEIGHT : ";
        cin >> w;

        cout << "ENTER HEIGHT IN CM : ";
        cin >> h;

        cout << "ENTER BASIC HEALTH (GOOD / SATISFACTORY / BAD) : ";
        cin.ignore();
        getline(cin , hel);

        cout << endl;
        BODYMASSINDEX BMI(n , w , h , a , g , hel);
        BMI.INFO();

        double PersonBMI = BMI.BMICalculator(w,h);

        cout << BMI.getName() << " BODY MASS INDEX (BMI) : " << PersonBMI << endl;

        BMI.BMICheck();

        return 0;
        
}
