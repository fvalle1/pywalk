import unittest
import sys, os
sys.path.append(os.getcwd())

class WalTests(unittest.TestCase):
    def test_import(self):
        import pywalk
        self.assertTrue(True)

    def test_step(self):
        from pywalk import step
        next = step(2, 2)
        self.assertLessEqual(next, 4.)

    def test_walk(self):
        from pywalk import run_walk
        run_walk()
        self.assertTrue(True)


    def test_arrival(self):
        from pywalk import get_arrival
        next = get_arrival(10)
        self.assertLessEqual(next, 2**10)

    def test_stats(self):
        from pywalk import get_arrival_list
        next = get_arrival_list(10)
        self.assertLessEqual(len(next), 10)

if __name__ == '__main__':
    unittest.main()
