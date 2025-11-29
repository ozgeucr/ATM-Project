# Derleyici ve Bayraklar
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Hedef Dosya Adı
TARGET = mainATM

# Kaynak Dosyalar (Ana dosya yeterli, çünkü diğerlerini include ile çekiyoruz)
SRCS = mainATM.cpp

# Varsayılan Hedef (make yazınca bu çalışır)
all: $(TARGET)

# Derleme Kuralı
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Temizlik Kuralı (make clean yazınca çalışır)
clean:
	rm -f $(TARGET) bank_database.txt transactions.txt

# Çalıştırma Kuralı (make run yazınca çalışır)
run: all
	./$(TARGET)