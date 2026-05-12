// ConsoleApplication1.cpp : 'main' 関数を含む。C++14 想定。

#include <iostream>
#include <string>

std::string ReverseUtf8(const std::string& s)
{
    std::string r;
    r.reserve(s.size());
    for (std::size_t i = s.size(); i > 0; ) {
        std::size_t j = i - 1;
        while (j > 0 && (static_cast<unsigned char>(s[j]) & 0xC0) == 0x80) --j;
        r.append(s.data() + j, i - j);
        i = j;
    }
    return r;
}

int main()
{
    const std::string original = "Hello World!";
    const std::string rev = ReverseUtf8(original);

    for (int i = 0; i < 10; ++i) {
        std::cout << ((i % 2 == 1) ? rev : original) << '\n';
    }

    std::cout << "Hello World!\n";
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
