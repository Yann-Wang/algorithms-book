/*
 * @lc app=leetcode.cn id=1410 lang=typescript
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start

function entityParser(text: string): string {
    const entityMap = {
        '&quot;': '"',
        '&apos;': `'`,
        '&amp;': '&',
        '&gt;': '>',
        '&lt;': '<',
        '&frasl;': '/'
    };
    let result = '';


    let i=0,j=0, str = '';
    let entityChar;

    while(i<text.length) {

        if (text[i] === '&') {
            str = '';
            j = i;
            while(j<text.length) {
                str += text[j];
                if (text[j] === ';') {
                    break;
                } else{
                    j++;
                }
            }

            entityChar = entityMap[str];
            if (text[j] === ';' && entityChar) {
                result += entityChar;
                i = j+1;
            } else {
                result += text[i];
                i++;
            }
        } else {
            result += text[i];
            i++;
        }
    }

    return result;

};
// @lc code=end

