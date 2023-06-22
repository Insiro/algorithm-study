from threading import Thread
from time import time


class Test:
    def __init__(self, solution) -> None:
        self.idx = 0
        self.worker = []
        self.solution = solution

    def checker(self, case, answer):
        idx = self.idx
        start_time = time()
        result = self.solution(case)
        duration = time() - start_time

        msg = "passed" if result == answer else "failed"
        print(f"test {idx} : {msg}, {duration:.4f} sec")

    def add_case(self, case, answer):
        t = Thread(target=self.checker, args=[case, answer])
        t.start()
        self.idx += 1
        self.worker.append(t)

    def end(self):
        for worker in self.worker:
            worker.join()
        print("all_test_finished")
