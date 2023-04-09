// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    map<char, long> letter_to_qtty;
    long missing_letters;
    long beg_sub_s, end_sub_s;
    string s, t;
    long last_added_id, first_added_id;

    bool map_has_already_ch(char ch)
    {
        return (letter_to_qtty.find(ch) != letter_to_qtty.end());
    }

    void init_vars(string s, string t)
    {
        for(char ch : t)
        {
            if(map_has_already_ch(ch))  letter_to_qtty[ch]++;
            else                        letter_to_qtty[ch] = 1;
        }

        missing_letters = t.size();

        beg_sub_s = end_sub_s = 0;

        this->s = s;
        this->t = t;

        last_added_id = -1;
        first_added_id = -1;
    }

    void add_letter_to_sub_s(long id_ch_sub_s)
    {
        char ch = s[id_ch_sub_s];

        if(id_ch_sub_s == last_added_id + 1)
        {
            if(letter_to_qtty[ch] > 0)
            {
                missing_letters--;
            }
            
            if(map_has_already_ch(ch)) 
            {
                letter_to_qtty[ch]--;
            }  

            last_added_id++;
            if(first_added_id == -1) first_added_id++;
        }  
    }

    void remove_letter_from_sub_s(long id_ch_sub_s)
    {
        char ch = s[id_ch_sub_s];
        if(id_ch_sub_s == first_added_id)
        {
            if(letter_to_qtty[ch] >= 0)
            {
                missing_letters++;
            }
            
            if(map_has_already_ch(ch)) 
            {
                letter_to_qtty[ch]++;
            }

            first_added_id++;
        }
    }

    bool has_found_sub_s()
    {
        return (missing_letters == 0);
    }

    string minWindow(string s, string t) {
        long best_beg_sub_s, best_end_sub_s;
        best_beg_sub_s = 0;
        best_end_sub_s = s.size() - 1;

        bool has_ever_found_sub_s = false;

        init_vars(s, t);

        for(; beg_sub_s < s.size(); beg_sub_s++)
        {
            for(; end_sub_s < s.size(); end_sub_s++)
            {
                add_letter_to_sub_s(end_sub_s);

                if(has_found_sub_s()) 
                {
                    has_ever_found_sub_s = true;

                    if(end_sub_s - beg_sub_s < best_end_sub_s - best_beg_sub_s)
                    {
                        best_beg_sub_s = beg_sub_s;
                        best_end_sub_s = end_sub_s;
                    }
                    break;
                }

            }

            remove_letter_from_sub_s(beg_sub_s);
        }

        long size_best_sub_s = best_end_sub_s - best_beg_sub_s + 1;
        if(!has_ever_found_sub_s) return ""; 
        return s.substr(best_beg_sub_s, size_best_sub_s);
    }
};