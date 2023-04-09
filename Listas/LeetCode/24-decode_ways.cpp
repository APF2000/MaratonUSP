// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    unordered_set<string> valid_encodings;

    void calculate_valid_encodings()
    {
        for(int i = 1; i <= 26; i++)
        {
            string encoding_str = to_string(i);
            valid_encodings.insert(encoding_str);
        }
    }

    bool is_valid_encoding(string s)
    {
        return (valid_encodings.find(s) != valid_encodings.end());
    }

    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int32_t> preceding_digits_to_num_decodings(n + 1, 0);
        preceding_digits_to_num_decodings[n] = 1;

        calculate_valid_encodings();

        for(int i = n - 1; i >= 0; i--)
        {            
            string small_sub_s = s.substr(i, 1);

            int32_t new_num_decodings = 0;

            if(is_valid_encoding(small_sub_s))
            {
                int32_t prev_num_decodings = preceding_digits_to_num_decodings[i + 1];
                new_num_decodings += prev_num_decodings;
            }

            if(i != s.size() - 1)
            {
                string big_sub_s = s.substr(i, 2);

                if(is_valid_encoding(big_sub_s))
                {
                    int32_t prev_num_decodings = preceding_digits_to_num_decodings[i + 2];
                    new_num_decodings += prev_num_decodings;
                }
            }

            preceding_digits_to_num_decodings[i] = new_num_decodings;
        }

        return preceding_digits_to_num_decodings[0];
    }
};