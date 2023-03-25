class Checker:
    """testcase validator"""

    def __init__(self, solution, preprocessor=None) -> None:
        """initalize testcase validator

        Args:
            solution : (args)=>answer
            preprocessor : when need to preprocess input, you can
        """
        self.solution = solution
        self.input = preprocessor
        self.case_num = 0

    def __call__(self, input, answer):
        """testcase validate"""
        self.case_num += 1
        input = input if self.input == None else self.input(input)
        output = self.solution(input)
        if answer != output:
            print(
                f"{self.case_num} : input : {input}, output : {output}, answer : {answer}"
            )
            assert True
