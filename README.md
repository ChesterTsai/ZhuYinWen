注意：如果你下載源代碼並使用Dev-C++這款編譯器的話，那麼你需要注意以下兩點。<br />
1. 你100%是個Windows用戶。<br />
2. 請在編譯器選項，連結器命令行中打上"-std=c++11"，讓編譯器可以讀到C++98沒有的指令跟函式庫。<br />

WARN: If you downloaded the source code and want to edit it using Dev-C++, there's two things you need to know.<br />
1. You're 100% a Windows user with no doubt.<br />
2. Please type "-std=c++11" in Compiler Options, linker command. For the compiler to read the codes and libraries that C++98 don't have.<br /><br />

# Windows使用者:<br />
按下右邊的Release按鈕，選擇最新的版本，並下載.exe檔即可在您的電腦上運行<br /><br />
※若您選擇下載源代碼，這是需要注意的：<br />
下載下來的源代碼需要被轉換成ASCII編碼以防止顯示亂碼，因為Windows是使用ASCII而不是Linux或Mac使用的UTF-8編碼。<br />
<br />
# Linux使用者:<br />
您可以選擇<br />
1.下載源碼，並自行編譯成執行檔。<br />
第一步（下載源碼）：

    git clone https://github.com/ChesterTsai/ZhuYinWen.git && cd ZhuYinWen
第二步（編譯成執行檔）：

    g++ -o ZhuYinWen.run ZhuYinWen.cpp
第三步（執行程式）：

    ./ZhuYinWen.run

### 或是<br />

2.直接下載最新版本。<br />
第一步（下載最新版本）：

    wget https://github.com/ChesterTsai/ZhuYinWen/releases/latest/download/ZhuYinWen.run
第二步（給予運行權限）：

    cmode +x ./ZhuYinWen.run
第三步（執行程式）：

    ./ZhuYinWen.run

<br /><br />
# For Windows Users:<br />
Press the "Release" button on the right hand side, choose the newest version, download the .exe file and run it on your PC.<br /><br />
※If you choose to download the source code, here what you need to know:<br />
Source code that you've downloaded need to be change into ASCII, since Windows is using ASCII instead of UTF-8 which is used in Linux and Mac.<br />
<br />
# For Linux Users:<br />
You can choose wether to<br />
1.Download the code and compile it by yourself.<br />
First step (Download the source code):

    git clone https://github.com/ChesterTsai/ZhuYinWen.git && cd ZhuYinWen
Second step (Compile it):

    g++ -o ZhuYinWen.run ZhuYinWen.cpp
Third step (Run the program):

    ./ZhuYinWen.run

### Or<br />

2.Download the latest version<br />
First Step (Download the latest version):

    wget https://github.com/ChesterTsai/ZhuYinWen/releases/latest/download/ZhuYinWen.run
Second step (Give it permission to run the file):

    cmode +x ./ZhuYinWen.run
Third step (Run the program):

    ./ZhuYinWen.run
