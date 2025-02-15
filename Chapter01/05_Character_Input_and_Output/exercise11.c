/* How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

// Answer: 단어 수 프로그램을 테스트하려면 공백, 탭 및 새 줄의 다양한 조합을 포함하는 다양한 문자열을 입력합니다.
//         가장 많은 버그를 발견할 수있는 입력은 연속으로 여러 개의 공백, 탭 및 새 줄을 포함하는 입력입니다.
//         예를 들어, "hello   world" 또는 "hello\tworld" 또는 "hello\nworld"와 같은 입력을 사용할 수 있습니다.