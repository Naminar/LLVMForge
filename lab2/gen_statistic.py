from argparse import ArgumentParser
import matplotlib.pyplot as plt

parser = ArgumentParser()
parser.add_argument('-s', '--static', action='store_true')

def addlabels(x,y):
    for i in range(len(x)):
        plt.text(i, y[i]//2, y[i], ha = 'center', color='white', size=6)

def create_stat(stat, name='stat'):
    plt.figure(figsize = (18/2,9/2), dpi = 150)
    plt.bar(stat.keys(), stat.values(), width=0.6)
    plt.xticks(fontsize=6, rotation=90)
    # addlabels(stat.keys(), list(stat.values()))
    plt.tight_layout()
    plt.savefig(f'{name}.jpeg')

if __name__ == '__main__':
    args = parser.parse_args()
    if args.static:
        stat = dict()
        with open('stat.txt', 'r') as file:
            for line in file:
                if line in stat.keys():
                    stat[line] += 1
                else:
                    stat[line] = 1

        plt.figure(figsize = (18/2,9/2), dpi = 150)
        plt.bar(stat.keys(), stat.values(), width=0.6)
        plt.xticks(fontsize=6, rotation=90)
        addlabels(stat.keys(), list(stat.values()))
        plt.tight_layout()
        plt.savefig('stat.jpeg')
    else:
        stat = dict()
        dump = open('stat_dyn.txt').read().split()
        print(dump)
        for (i, word) in enumerate(dump):
            if i > 0:
                line = f'{dump[i]}<<{dump[i-1]}'
                if line in stat.keys():
                    stat[line] += 1
                else:
                    stat[line] = 1
        create_stat(stat, 'stat_dyn')