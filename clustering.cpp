#include "matplotlibcpp.h"
#include <vector>
#include <random>
#include <iostream>
#include <utility> 
#include <math.h>
using namespace std; 
namespace plt = matplotlibcpp;

struct point{
	double x,y;
};
using DataFrame = std::vector<point>;


auto make_uniform_dataset(int nb_point, double bound_min , double bound_max)
{
 
auto x = std::vector<double>(nb_point);
auto y = std::vector<double>(nb_point);
auto uniform = std::uniform_real_distribution<double>(bound_min,bound_max);
auto rg= std::default_random_engine();

	for(auto i =0 ; i< nb_point ; ++i)
   	{
	x[i]=uniform(rg);
	y[i]=uniform(rg);
   	}

return std::make_pair(x,y);
}


auto make_blob_dataset(int nb_point_per_blob,int nb_blobs ,double bound_min , double bound_max )
{

	auto x = std::vector<double>();
	x.reserve(nb_point_per_blob*nb_blobs);
	auto y = std::vector<double>();
	y.reserve(nb_point_per_blob*nb_blobs);
       	auto rg= std::default_random_engine();
	
	for(auto i=0;i<nb_blobs;++i){

	std::normal_distribution<double> generateurdex (xblob_centers[i],0.3);
	std::normal_distribution<double> generateurdey (yblob_centers[i],0.3);
		for(auto j=0; j<nb_point_per_blob; ++j){
	
			auto xx= generateurdex(rg); 
			auto yy= generateurdey(rg) ;
			x.push_back(xx);
			y.push_back(yy);
		}
	}
	
return std::make_pair(x,y);
}
double carré(double value) {
  return value * value;
}

double distance(point one,point second) {
return carré(one.x - second.x) + square(one.y - second.y);
}	

auto k_means(std::vector<double>x,std::vector<double>y,double nb_cluster,double bound_min,double bound_max,int nombre.d'iterations,int nb_point,const DataFrame& data) {
	auto centers=make_uniform_dataset(nb_cluster,bound_min,bound_max);
	auto xcenters=centers.first;
	auto ycenters=centers.second;
  std::vector<size_t> assignments(data.size());
  for (size_t M = 0; M < nombre.d'iterations; ++M) { 
    for(size_t k=0 ;k<nb_point ;++k){
      auto meilleur.distance = std::numeric_limits<double>::max();
      auto meilleur.cluster = 0;
      for (auto l = 0; l <nb_cluster; ++l) {
        point v{xcenters[l], ycenters[l]};
        const double distance = distance(data[k],v);
        if (distance < meilleur.distance) {
          meilleur.distance = distance;
          meilleur.cluster = l;
        }
      }
      assignments[k] = best_cluster;

}
}
//b/recalcul les centres en utilisants les ensembles.
//moyenne de toute les coordonée des poiints qui font parties des centres
}

int main ()
{
auto bound_min =-10;
auto bound_max=10;
auto nb_point=150;
auto nb_blobs=3;
auto nb_point_per_blob=50;
auto nb_cluster=3;
auto nombre.d'iterations =200;
auto S =make_blob_dataset(nb_point_per_blob , nb_blobs ,bound_min ,bound_max );
plt::plot(S.first,S.second,"o");
plt::show();
}

