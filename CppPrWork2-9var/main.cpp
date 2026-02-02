#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/string.h>
#include <wx/tokenzr.h>
wx-config --version


#include <iostream>

bool IsWordValid(const wxString &word)
{
    if (word.length() < 2)
        return false;

    wxChar first = wxTolower(word[0]);
    wxChar last = wxTolower(word[word.length() - 1]);

    return first == last;
}

int main()
{
    wxTextFile file;
    if (!file.Open("input.txt"))
    {
        std::cout << "Не удалось открыть файл\n";
        return 1;
    }

    wxString result;

    for (size_t i = 0; i < file.GetLineCount(); i++)
    {
        wxString line = file.GetLine(i);

        wxStringTokenizer tokenizer(line, " ,.!?;:-()\t");
        while (tokenizer.HasMoreTokens())
        {
            wxString word = tokenizer.GetNextToken();

            if (IsWordValid(word))
            {
                result += word + " ";
            }
        }
    }

    file.Close();

    // Вывод результата
    std::cout << "Слова, начинающиеся и заканчивающиеся одной буквой:\n";
    std::cout << result.ToStdString() << std::endl;

    return 0;
}
