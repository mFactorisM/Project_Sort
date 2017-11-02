# Project_Sort

1) Скачать Wpdpack по ссылке: https://www.winpcap.org/install/bin/WpdPack_4_1_2.zip
2) Закинуть в корень диска C:\ или любой другой путь, при этом заменив путь к библиотекам.
3) Добавить следующие строки в .pro:

INCLUDEPATH += "C:\WpdPack\Include" \n
INCLUDEPATH += "C:\WpdPack\Lib" \n
LIBS += -L"C:\WpdPack\Lib" -lwpcap -lpacket \n
LIBS += -lws2_32 \n
