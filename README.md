# compress-and-decompress-files-using-huffman-coding

* This is a program to compress and decompress a file using huffman coding algorithm.</br>
Note: the program compress only text files</br>

<h3> Getting Started </h3>
- If you know how to compile c program you can use any c complier. </br>
- If you don't know how to compile c program with multiple directories and files you need to have gcc compiler, git and Makefile installed on your system and follow the steps bellow:</br>

1. Open your terminal or command line </br>
2. Clone this repository by typing this command: git clone https://github.com/Abderrahmanehocine/compress-and-decompress-files-using-huffman-coding.git</br>
3. Go to the directory that contain the files of the code: cd compress-and-decompress-files-using-huffman-coding</br>
4. Compile the program using the Makefile(Type make in the cmd): make</br>
5. Move the text file that you want to compress in the directory that contain the main.c file</br>
6. To run the program type: ./huffman -c file1.txt file2.txt</br>

file1.txt: is the name of the file that you want to compress</br>
file2.txt: the name of the file that you want the compressed data will be in it (file2 will be created automatcly you just need to give it a name)</br>

<h3> Example </h3>
- I have a text file contain data that I want to compress, the neme of the file is: data.txt,  and I want the compressed data to be in a file named: output.txt<br>
- The run command is: ./huffman -c data.txt output.txt</br>

<h3> Output </h3>
- The program will create a file names output.txt(depand on the name that you want) and write the huffman tree with the code of the data </br>

<h3> Decompress </h3>
- If you want to decompress the file you just need to run the program again using this command: ./huffman -d ouput.txt data1.txt</br>
- I names the file data1.txt just to compare id the data will be the same with my previous data in the file data.txt </br>

<h3> Contact </h3>
- If you have any question contact me at : hocineabderrahmane@duck.com
