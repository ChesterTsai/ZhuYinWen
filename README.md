注意：如果你下載源碼並使用Dev-C++這款編譯器的話，那麼你需要注意以下兩點。<br />
1. 你100%是個Windows用戶。<br />
2. 請在編譯器選項、連結器命令行中打上「-std=c++11」，讓編譯器可以讀到C++98沒有的指令跟函式庫。<br />
※若您選擇下載源碼，這是需要注意的：<br />
下載下來的源碼需要被轉換成ASCII編碼以防止顯示亂碼，因為Windows是使用ASCII而不是Linux或Mac使用的UTF-8編碼。<br />

# Linux:<br />
您可以選擇<br />
<br>
1.下載源碼，並自行編譯成執行檔。<br />
第一步（下載源碼）：

    git clone https://github.com/ChesterTsai/ZhuYinWen.git && cd ZhuYinWen
第二步（編譯成執行檔）：

    g++ ZhuYinWen.cpp -o ZhuYinWen.run
第三步（執行程式）：

    ./ZhuYinWen.run
<br />
<br />
<br />
如果您想一次執行完，也可以把指令全部串接起來：

    git clone https://github.com/ChesterTsai/ZhuYinWen.git && cd ZhuYinWen && g++ ZhuYinWen.cpp -o ZhuYinWen.run && ./ZhuYinWen.run

### 或是<br />

2.直接下載最新版本。<br />
第一步（下載最新版本）：

    wget https://github.com/ChesterTsai/ZhuYinWen/releases/latest/download/ZhuYinWen.run
第二步（給予運行權限）：

    chmod +x ./ZhuYinWen.run
第三步（執行程式）：

    ./ZhuYinWen.run
<br />
<br />
<br />
如果您想一次執行完，也可以把指令全部串接起來：

    wget https://github.com/ChesterTsai/ZhuYinWen/releases/latest/download/ZhuYinWen.run && chmod +x ./ZhuYinWen.run && ./ZhuYinWen.run
