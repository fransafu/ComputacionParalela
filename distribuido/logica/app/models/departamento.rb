class Departamento < ApplicationRecord
  belongs_to :facultad
  has_many :asignaturas
  has_many :docentes
end
