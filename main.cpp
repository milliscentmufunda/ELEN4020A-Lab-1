#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include <pthread.h>

vector<vector<int> > rank2TensorAdd(const vector<vector<int> >& A, const vector<vector<int> >& B){

    vector<vector<int> > C;

        for(unsigned j = 0; j < A.size(); j++){

            vector <int > temp1D;

            for(unsigned k = 0; k < A.at(j).size(); k++){

                temp1D.push_back(A[j][k] + B[j][k]);

            }

            C.push_back(temp1D);
        }

	return C;
}

vector<vector<int> > rank2TensorMult(const vector<vector<int> >& A, const vector<vector<int> >& B){

	//vector<vector<int>> C(A.size())(B.size());
	vector< vector<int> > C(A.size(), vector<int>(B.size()));

	for(unsigned i = 0; i < A.size(); i++){

		for(unsigned j = 0; j < A.size(); j++){

            int c = 0;

            for(unsigned k = 0; k < A.size(); k++){

                c += A[i][k] * B[k][j];

            }

			C[i][j] = c;

		}

	}

	return C;
}

vector<vector<vector<int> > > rank3TensorAdd(const vector<vector<vector<int> > >& A, const vector<vector<vector<int> > >& B){

    vector<vector<vector<int> > > C;

    for(unsigned i = 0; i < A.size(); i++){

        vector <vector<int > > temp2D;

        for(unsigned j = 0; j < A.at(i).size(); j++){

            vector <int > temp1D;

            for(unsigned k = 0; k < A.at(i).at(j).size(); k++){

                temp1D.push_back(A[i][j][k] + B[i][j][k]);

            }

            temp2D.push_back(temp1D);
        }

        C.push_back(temp2D);
    }

	return C;
}

vector<vector<vector<int> > > rank3TensorMult(const vector<vector<vector<int> > >& A, const vector<vector<vector<int> > >& B){

    vector<vector<vector<int> > > C;

    for(unsigned i = 0; i < A.size(); i++){

        vector <vector<int > > temp2D;

        for(unsigned j = 0; j < A.at(i).size(); j++){

            vector <int > temp1D;

            for(unsigned k = 0; k < A.at(i).at(j).size(); k++){

                int c = 0;

                for(unsigned x = 0; x < A.at(i).at(j).size(); x++){

                        c += A[k][j][x] * B[k][x][i];

                }

                temp1D.push_back(c);

            }

            temp2D.push_back(temp1D);
        }

        C.push_back(temp2D);
    }

	return C;
}



int main(void){

    int N = 10;

    while(N < 21){

        srand(time(NULL));

        vector<vector<int> > A;
        vector<vector<int> > B;
        vector<vector<int> > arrayMult2D;
        vector<vector<int> > arrayAdd2D;

        for(int i = 0; i < N; i++){
            vector <int> temp1;
            vector <int> temp2;
            for(int j = 0; j < N; j++){

                temp1.push_back(rand()%21);
                temp2.push_back(rand()%21);

            }
            A.push_back(temp1);
            B.push_back(temp2);
        }

        arrayAdd2D = rank2TensorAdd(A,B);
        arrayMult2D = rank2TensorMult(A,B);

        vector<vector<vector<int> > > C;
        vector<vector<vector<int> > > D;
        vector<vector<vector<int> > > arrayAdd3D;
        vector<vector<vector<int> > > arrayMult3D;

        for(int k = 0; k < N; k++){

            vector<vector<int> > temp2D_1;
            vector<vector<int> > temp2D_2;

            for(int i = 0; i < N; i++){

                vector <int> temp1D_1;
                vector <int> temp1D_2;

                for(int j = 0; j < N; j++){

                    temp1D_1.push_back(rand()%21);
                    temp1D_2.push_back(rand()%21);

                }
                temp2D_1.push_back(temp1D_1);
                temp2D_2.push_back(temp1D_2);
            }

            C.push_back(temp2D_1);
            D.push_back(temp2D_2);

        }


        arrayAdd3D = rank3TensorAdd(C,D);
        arrayMult3D = rank3TensorMult(C,D);

        N+= 10;
    }



	return 0;

}
