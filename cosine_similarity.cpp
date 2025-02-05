#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int char_size = 256;

int opening_files(const string &file1, const string &file2, const string &output_file)
{
    ifstream fin(file1);
    ifstream f(file2);
    ofstream fout(output_file);

    if (!fin || !f || !fout)
    {
        cout << "Error in opening the files!" << endl;
        return -1;
    }

    char line[80];

    cout << "Contents of " << file1 << ":" << endl;
    fout << "Contents of " << file1 << ":" << endl;
    while (fin.getline(line, 80))
    {
        cout << line << endl;
        fout << line << endl;
    }
    fin.close();
    fout << endl;

    cout << "Contents of " << file2 << ":" << endl;
    fout << "Contents of " << file2 << ":" << endl;
    while (f.getline(line, 80))
    {
        cout << line << endl;
        fout << line << endl;
    }
    f.close();
    fout.close();

    return 0;
}

void frequency(const string &filename, int freq[])
{
    ifstream file(filename);
    char ch;
    while (file.get(ch))
    {
        freq[(char)ch]++;
    }
    file.close();
}

int cosine_value(const int freq1[], const int freq2[])
{
    int dot_product = 0, file1_words = 0, file2_words = 0;

    for (int i = 0; i < char_size; i++)
    {
        dot_product += freq1[i] * freq2[i];
        file1_words += freq1[i] * freq1[i];
        file2_words += freq2[i] * freq2[i];
    }

    if (file1_words == 0 || file2_words == 0)
        return 0.0;

    return dot_product / (sqrt(file1_words) * sqrt(file2_words));
}

void cosin_sim(const string &file1, const string &file2, const string &output_file)
{
    int freq1[char_size] = {0}, freq2[char_size] = {0};

    frequency(file1, freq1);
    frequency(file2, freq2);

    int similarity = cosine_value(freq1, freq2);

    cout << "Cosine Similarity: " << similarity << endl;

    ofstream fout(output_file);
    if (fout)
    {
        fout << "\nCosine Similarity: " << similarity << endl;
        fout.close();
    }
}

int main()
{
    string file1 = "file1.txt";
    string file2 = "file2.txt";
    string output_file = "output_file.txt";
    cosin_sim(file1, file2, output_file);

    return 0;
}
