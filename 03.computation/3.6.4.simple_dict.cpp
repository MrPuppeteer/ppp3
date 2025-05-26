// simple dictionary: list of sorted words
import std;
using namespace std;

int main() {
  vector<string> words;
  for (string temp; cin>>temp;)         // read whitespace-separated words
    words.push_back(temp);              // put into vector
  cout << "Number of words:" << words.size() << '\n';

  ranges::sort(words);                  // sort the words

  for (size_t i = 0; i<words.size(); ++i)
    if (i==0 || words[i-1]!=words[i])   // is this a new word?
      cout << words[i] << '\n';
}
