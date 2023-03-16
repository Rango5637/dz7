#pragma once;
using namespace std;


class IntegerArray {
	short _length, *_data;
public:

	IntegerArray() = default;
	
	IntegerArray(short length) {
		this->_length = length;

		if ( length <=0 ) {
			system("cls");
			throw "Ошибка, длина массива не может быть равна нулю!!";
		}
		if (length > 0) {
			_data = new short[length] {};
		}
	}
	void Show() {
		short leng = _msize(_data) / sizeof(short);
		system("cls");
		cout << "размер массива " << leng << endl;
	}
	~IntegerArray() {
		delete[] _data;
	}

	void reset() {
		delete[] _data;
		_data = nullptr;
		_length = 0;
	}

	short& operator[](short i) {
		if (i >= 0 and i < _length) {
			return _data[i];
		}
	}

	void reallocate(short newLength) {
		reset();

		if (newLength <= 0) {
			return;
		}

		_data = new short[newLength];
		_length = newLength;
	}

	void resize(short newLength) {

		if (newLength == _length) {
			return;
		}

		if (newLength <= 0) {
			reset();
			return;
		}

		short* data{ new short[newLength] };

		if (_length > 0) {
			short elementsToCopy{ (newLength > _length) ? _length : newLength };
			
			for (short index{ 0 }; index < elementsToCopy; ++index) {
				data[index] = _data[index];
			}
		}

		delete[] _data;

		_data = data;
		_length = newLength;
	}

	void Before(short value, short index) {


		if (index >= 0 && index <= _length) {}
		
		short* data{ new short[_length + 1] };
		
		for (int before{ 0 }; before < index; ++before) {
			data[before] = _data[before];
		}


		data[index] = value;

		for (int after{ index }; after < _length; ++after) {
			data[after + 1] = _data[after];
		}

		delete[] _data;
		_data = data;
		++_length;
	}

	void remove(int index) {

		if (index >= 0 && index < _length) {}

		if (_length == 1) {
			reset();
			return;
		}

		short* data{ new short[_length - 1] };

		for (int before{ 0 }; before < index; ++before) {
			data[before] = _data[before];
		}

		for (int after{ index + 1 }; after < _length; ++after) {
			data[after - 1] = _data[after];
		}

		delete[] _data;
		_data = data;
		--_length;
	}

	void start(int value) {
		Before(value, 0); 
	}
	void End(int value) { 
		Before(value, _length); 
	}

	int getLength() const {
		return _length; 
	}
};

void menu() {
	system("cls");
	cout << "выбор действий:\n1. Посмотреть массив\n2. Изменить размер массива\n3. Удалить элемент в массиве"
			"\n4. Заменить число\n5. Записать значения в начало и конец массива"<< endl;

}