import matplotlib.pyplot as plt

def addlabels(x,y):
    for i in range(len(x)):
        plt.text(i, y[i]//2, y[i], ha = 'center', color='white', size=6)

if __name__ == '__main__':
    stat = dict()
    with open('stat.txt') as file:
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
