# [Learning Gender-Neutral Word Embeddings (EMNLP 2018)](https://arxiv.org/abs/1809.01496)
[Jieyu Zhao](http://jyzhao.net), Yichao Zhou, Zeyu Li, [Wei Wang](http://web.cs.ucla.edu/~weiwang/), [Kai-Wei Chang](http://kwchang.net) 

## Abstract
Word embedding models have become a fundamental component in a wide range of Natural Language Processing (NLP) applications. However, embeddings trained on human-generated corpora have been demonstrated to inherit strong gender stereotypes that reflect social constructs. To address this concern, in this paper, we propose a novel training procedure for learning gender-neutral word embeddings. Our approach aims to preserve gender information in certain dimensions of word vectors while compelling other dimensions to be free of gender influence. Based on the proposed method, we generate a Gender-Neutral variant of GloVe (GN-GloVe). Quantitative and qualitative experiments demonstrate that GN-GloVe successfully isolates gender information without sacrificing the functionality of the embedding model.

------
## Updates:

**The coreference model in this paper is based on end2end 2017 version.**

Please note the embeddings trained by us didn't do lowercase.

**Please modify the debias.sh to your own datapath (line 18).**

------
01/14/2019

We also train the GN-GloVe using 1-billion training data. It can be downloaded [here](https://drive.google.com/a/g.ucla.edu/file/d/1g1QPqbIlQorwlfGShtPbZVk6mfwodQgE/view?usp=sharing).
There are 142527 tokens in this embedding corpus.

------
In Table 1 and 3, it should be "Hard-GloVe". And on Page 5, it should be "OntoNotes". 

Our pretrained word embeddings (using wikidump dataset; 322636 tokens in the embeddings) can be found [here](https://drive.google.com/a/g.ucla.edu/file/d/1v82WF43w-lE-vpZd0JC1K8WYZQkTy_ii/view?usp=sharing). And GloVe trained on this Wikidump dataset can be found [here](https://drive.google.com/open?id=1jrbQmpB5ZNH4w54yujeAvNFAfVEG0SuE). 

The seed words we use in our paper is under [wordlist](/wordlist).

The SemBias dataset can be found under [SemBias](/SemBias/). The last 40 instances are the "subset" we used in our paper.

You can run the code using "debias.sh" (Please change the corresponding parameters).



### License
See the LICENSE file.
