#include "DownSample.h"

using namespace std;

DownSample::DownSample(Point2D* p_ul, int res_x, int res_y, int pixel_width, int pixel_height, int tolerance) {
  this->res_x = res_x;
  this->res_y = res_y;

  this->pixel_width = pixel_width;
  this->pixel_height = pixel_height;
  this->tolerance = tolerance;

  this->boundingBox.ul_x = p_ul->x;
  this->boundingBox.ul_y = p_ul->y;
  this->boundingBox.lr_x = p_ul->x + pixel_width;
  this->boundingBox.lr_y = p_ul->y + pixel_height;

  this->image = NULL;
}

bool DownSample::sample(Point2D* p) {
  if (!boundingBox.inside(p->x, p->y, pixel_width * tolerance, pixel_height
                          * tolerance))
    return false;
  else {
    int cx = p->x / pixel_width;
    int cy = p->y / pixel_height;

    //TODO figure appropriate growth rate
    if (image == NULL || cx >= this->res_x || cy >= this->res_y) {
      int ncx = max(this->res_x, (cx));
      int ncy = max(this->res_y, (cy));
      resize(ncx * 2, ncy * 2);
    }

    PixelBox* pb = (*image)[cx][cy];

    if (pb == NULL) {
      int ul_x = cx * pixel_width;
      int ul_y = cy * pixel_height;
      int lr_x = ul_x + pixel_width;
      int lr_y = ul_y + pixel_height;
      pb = new PixelBox(ul_x, ul_y, lr_x, lr_y);
      (*image)[cx][cy] = pb;
    }

    boundingBox.adjustTo(pb);
    pixelBoxes.push_back(pb);
    return true;
  }
}

void DownSample::resize(int num_x, int num_y) {
  int offset = 0;
  if (image == NULL)
    image = new PB_Image(boost::extents[num_x][num_y]);
  else {
    offset = this->res_x * this->res_y;
    image->resize(boost::extents[num_x][num_y]);
  }

  std::fill(image->data() + offset, image->data() + image->num_elements(),
            (PixelBox*) NULL);

  this->res_x = num_x;
  this->res_y = num_y;
}

list<PixelBox*> DownSample::getPixels() {
  return pixelBoxes;
}

BBox DownSample::getBoundingBox() {
  return this->boundingBox;
}