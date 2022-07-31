
std::vector<Triangle2f> clipped_triangles;



Line2f screen_boundary[4] = {Line2f(Vector2f(0.0f,               0.0f),                 Vector2f(this->window_width, 0.0f)),
                             Line2f(Vector2f(this->window_width, 0.0f),                 Vector2f(this->window_width, this->window_hight)),
                             Line2f(Vector2f(this->window_width, this->window_hight),   Vector2f(0.0f,               this->window_hight)),
                             Line2f(Vector2f(0.0f,               this->window_hight),   Vector2f(0.0f,               0.0f))};

Vector2f((rotated_vertex_pojection_2D.x * this->window_width) + 0.5f * (this->window_width + 1.0f),
                (rotated_vertex_pojection_2D.y * this->window_width) + 0.5f * (this->window_hight + (this->window_hight / this->window_width)));
