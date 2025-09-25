
#include <iostream>
using namespace std;

class Neyron
{

private:
	double weight = 0.5;
	double lastError = 0.0;
	double smooting = 0.00001;
public:
	int ProcessInputData(int input) {
		input = input * weight;


		return input;

	}
	/*
	double RestoreInputData(double output) {
		if (weight == 0)
		{
			return 0;
		}
		return output / weight;

	}
	*/
	void Train(double input, double Exceptresult) {

		auto actualresult = input * weight;
		lastError = Exceptresult - actualresult;
		if (input != 0)
		{

			auto correction = (lastError / actualresult) * smooting;
			weight += correction;
		}

	}


	static void BASS() {

		double int2 = 83.95;
		double int1 = 1;
		double result = 0;
		Neyron neuron;
		int i = 0;
		do
		{
			i++;
			neuron.Train(int1, result);
			if (i % 10000 == 0)
			{

				cout << "Итерация" << " " << i << endl << "ошибка: " << neuron.lastError;
			}
		} while (neuron.lastError > neuron.smooting || neuron.lastError < -neuron.smooting);
		cout << endl;
		int a;
		cin >> a;
		cout << neuron.ProcessInputData(a) <<a<<endl;

	}



};


int main() {
	setlocale(LC_ALL, "ru");
	Neyron::BASS();
	cin.get();
	return 0;

}