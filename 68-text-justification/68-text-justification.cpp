class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        const int totalWords = words.size()-1;
        for (int begin=0, moreWords=0; begin<=totalWords; begin=moreWords) {
            string currentBlock(maxWidth, ' ');
            /* In problem statement, it is specified that each word is guaranteed to be
             * grether than 0 and not exceed maxWidth, so I can safely add first word. */
            currentBlock.replace(0, words[begin].size(), words[begin]);
            /* Now current block of text is ready with first word and remainig spaces,
             * I just need to calculate how many more words I can fit in this block. */
            int remainingSpace = maxWidth - words[begin].size();
            for (moreWords=begin+1; moreWords <=totalWords && words[moreWords].size() < remainingSpace; moreWords++) {
                /* First word in current block is already added before this for loop.
                 * Additional word(s) can be added in current justification block. As this
                 * is additional word, at least one space is needed in calculation
                 * for remaining space. Above '<' condition make sure that we have space for
                 * one additional space */
                remainingSpace -= words[moreWords].size()+1;
            }
            /* Word joints are total separating gap between words, for which we need to do
             * space management */
            int wordJoints = moreWords - begin -1;
            if (wordJoints) {
                /*Ok so we have more than one word in this justification block*/
                int evenlyDistributedSpace = 1; /*One space is already provisioned in above loop */
                int unEvenSpace = 0;
                if (moreWords <= totalWords) {
                /* Control is here means current justification block is not the last
                 * block, so we need to do some mathematics on remaining space and evenly
                 * distribute it between the words (word joints). Remember for last block
                 * this is not needed as it is left aligned and additional words are only
                 * placed one white space apart */
                    evenlyDistributedSpace += remainingSpace / wordJoints;
                    unEvenSpace = remainingSpace % wordJoints;
                }
                for (int i=begin+1, index=words[begin].size(); i < moreWords; i++) {
                    index += evenlyDistributedSpace + (unEvenSpace-- > 0);
                    currentBlock.replace(index, words[i].size(), words[i]);
                    index += words[i].size();
                }
            }
            result.push_back(currentBlock);
        }
        return result;
    }
};