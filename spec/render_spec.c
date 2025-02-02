#include "src/specc.h"
#include "../headers/render.h"
#include "spec_helper.h"

// TODO - center rectangle

module(render_spec, {

  describe("render", {
  
    context("create_rectangle_between", {
  
      it("creates rectangle between identical points", {
        Vec2f size = {0,1};
        Vec2f p = {5,10};
        Rectangle* r = create_rectangle_between(p,p,1);
        should_vectorf_eq(p,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(0.f,rectangle_rot(r),0.f);
        rectangle_destroy(r);
      });

      it("creates rectangle with zero thickness", {
        Vec2f size = {0,0};
        Vec2f p = {5,10};
        Rectangle* r = create_rectangle_between(p,p,0);
        should_vectorf_eq(p,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(0.f,rectangle_rot(r),0.f);
        rectangle_destroy(r);
      });

      it("creates rectangle with some thickness", {
        Vec2f size = {0,5};
        Vec2f p = {5,10};
        Rectangle* r = create_rectangle_between(p,p,5);
        should_vectorf_eq(p,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(0.f,rectangle_rot(r),0.f);
        rectangle_destroy(r);
      });

      it("creates rectangle between horizontal points", {
        Vec2f size = {5,1};
        Vec2f p1 = {5,10};
        Vec2f p2 = {10,10};
        Vec2f pos = {5,9.5};
        Rectangle* r = create_rectangle_between(p1,p2,1);
        should_vectorf_eq(pos,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(0.f,rectangle_rot(r),0.f);
        rectangle_destroy(r);
      });

      context("between vertical points", {
        Vec2f size = {5,1};
        Vec2f p1 = {5,5};
        Vec2f p2 = {5,10};

        it("creates rectangle (pointing up)", {
          Vec2f pos = {5.5,5};
          Rectangle* r = create_rectangle_between(p1,p2,1);
          should_vectorf_eq(pos,rectangle_pos(r));
          should_vectorf_eq(size,rectangle_size(r));
          should_float_eq(90.f,rectangle_rot(r),0.001f);
          rectangle_destroy(r);
        });

        it("creates rectangle (pointing down)", {
          Vec2f pos = {4.5,10};
          Rectangle* r = create_rectangle_between(p2,p1,1);
          should_vectorf_eq(pos,rectangle_pos(r));
          should_vectorf_eq(size,rectangle_size(r));
          should_float_eq(270.f,rectangle_rot(r),0.f);
          rectangle_destroy(r);
        });
      });

      it("creates rectangle between diagonal points", {
        Vec2f size = {sqrt(50),1};
        Vec2f p1 = {5,5};
        Vec2f p2 = {10,10};
        Vec2f pos = {5 + sqrt(2)/4,5 - sqrt(2)/4};
        Rectangle* r = create_rectangle_between(p1,p2,1);
        should_vectorf_eq(pos,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(45.f,rectangle_rot(r),0.001f);
        rectangle_destroy(r);
      });

      it("creates rectangle with first point to the right of the second point", {
        Vec2f size = {-5,-1};
        Vec2f p1 = {5,10};
        Vec2f p2 = {10,10};
        Vec2f pos = {10,10.5};
        Rectangle* r = create_rectangle_between(p2,p1,1);
        should_vectorf_eq(pos,rectangle_pos(r));
        should_vectorf_eq(size,rectangle_size(r));
        should_float_eq(0.f,rectangle_rot(r),0.f);
        rectangle_destroy(r);
      });
    });

    context("points_to_shapes", {
      it("converts zero points", {
        PointsConfig cfg = points_config(0,1,1);
        Vec2f* p = NULL;
        Shape* r = NULL;
        points_to_shapes(p,r,cfg);
      });

      context("one point", {
        PointsConfig cfg = points_config(1,2,1);

        it("converts with correct position", {
          Shape* r = calloc(1,sizeof(Shape));

          cfg.circle_radius = 1;
          Vec2f p1[1] = {{3,14}};
          Vec2f a1 = {3-1,14-1};
          points_to_shapes(p1,r,cfg);
          should_vectorf_eq(a1,circle_pos(shape_as_circle(r[0])));
          shape_destroy(r[0]);

          cfg.circle_radius = 2;
          Vec2f p2[1] = {{2,71}};
          Vec2f a2 = {2-2,71-2};
          points_to_shapes(p2,r,cfg);
          should_vectorf_eq(a2,circle_pos(shape_as_circle(r[0])));
          shape_destroy(r[0]);
          free(r);
        });

        it("converts with correct size", {
          Shape* r = calloc(1,sizeof(Shape));

          cfg.circle_radius = 1;
          Vec2f p1[1] = {{3,14}};
          points_to_shapes(p1,r,cfg);
          should_eq(1,circle_radius(shape_as_circle(r[0])),float);
          shape_destroy(r[0]);

          cfg.circle_radius = 2;
          Vec2f p2[1] = {{2,71}};
          points_to_shapes(p2,r,cfg);
          should_eq(2,circle_radius(shape_as_circle(r[0])),float);
          shape_destroy(r[0]);
          free(r);
        });
      });

      context("many points", {
        PointsConfig cfg = points_config(2,2,1);

        it("adds rectangle between two points", {
          Shape* s = calloc(3,sizeof(Shape));

          cfg.rect_thickness = 3;
          Vec2f p[2] = {{3,14},{15,92}};
          Vec2f a = {3-1,14-1};
          Vec2f b = {15-1,92-1};
          Rectangle* r = create_rectangle_between(p[0],p[1],3);
          points_to_shapes(p,s,cfg);
          should_vectorf_eq(a,circle_pos(shape_as_circle(s[0])));
          should_rect_eq(r,shape_as_rect(s[1]));
          should_vectorf_eq(b,circle_pos(shape_as_circle(s[2])));
          rectangle_destroy(r);
          shape_destroy(s[0]);
          shape_destroy(s[1]);
          shape_destroy(s[2]);
          free(s);
        });

        it("connects three points", {
          Shape* s = calloc(5,sizeof(Shape));

          cfg.num_points = 3;
          cfg.rect_thickness = 2;
          Vec2f p[3] = {{3,14},{15,92},{65,35}};
          Vec2f a = {3-1,14-1};
          Vec2f b = {15-1,92-1};
          Vec2f c = {65-1,35-1};
          Rectangle* r1 = create_rectangle_between(p[0],p[1],2);
          Rectangle* r2 = create_rectangle_between(p[1],p[2],2);
          points_to_shapes(p,s,cfg);
          should_vectorf_eq(a,circle_pos(shape_as_circle(s[0])));
          should_rect_eq(r1,shape_as_rect(s[1]));
          should_vectorf_eq(b,circle_pos(shape_as_circle(s[2])));
          should_rect_eq(r2,shape_as_rect(s[3]));
          should_vectorf_eq(c,circle_pos(shape_as_circle(s[4])));
          rectangle_destroy(r1);
          rectangle_destroy(r2);
          shape_destroy(s[0]);
          shape_destroy(s[1]);
          shape_destroy(s[2]);
          shape_destroy(s[3]);
          shape_destroy(s[4]);
          free(s);
        });
      });
    });
  });
});