# FakeGrayscale
Display static grayscale image on GU7000-series VFD display from Noritake Itron.

# How it works ? 

NOTE:It's just the concpet that has not been tested yet. But in theory should work.

The display I would like to use is GU280x16G-7000. This display is capable of 8 levels display brigthness. and It be able to send display command and display data without changing between 2 data input modes. And we can change the brightness everytime !
It came across a idea about If we can make the display to display the bitmap data as frame(s) and every frame has it own bright ness level. that's mean we combine many frame into one static image by tricking our eyes using persistence of vision method. 

Start from the initializing progress in void setup then jump to void loop. This begins the process of FakeGrayscale. 

![alt text](https://raw.githubusercontent.com/TiNredmc/FakeGrayscale/master/Principles.png)


# Requirement

Software : 
Arduino IDE and Noritake Itron GU7000 library https://www.noritake-elec.com/user/download?id=Arduino_Noritake_VFD_GU7000&category=10&type=gu7000

Hardware :
In this case I use GU280x16G-7000 Display. You can use any GU7000 series. About Microcontroller. I use ESP-01S.

# The library

I modified the Library to at lease fix compile error. but not testing the library yet. 

